/**
 *  Auteur       : Bourennane Amine
 *  Creation     : 30-11-2020
 *  Modification : 30-11-2020
**/

#define IMAGE_SIZE 512
#define IMAGE_SIZE_X IMAGE_SIZE
#define IMAGE_SIZE_Y IMAGE_SIZE
#define PIXEL_SIZEOF 4
#include <stdlib.h>
#include <math.h>

typedef double Pix[PIXEL_SIZEOF];
typedef Pix Img[IMAGE_SIZE_Y][IMAGE_SIZE_X];

typedef struct  s_lst
{
    int             x;
    int             y;
    int             len;
    struct s_lst    *next;
}               t_cell,
                *t_lst;

static t_lst    new_elem(int x, int y)
{
    t_lst   ret;

    if (!(ret = (t_lst) malloc(sizeof(t_cell))))
        return (NULL);
    ret->x = x;
    ret->y = y;
    ret->len = 1;
    ret->next = NULL;
    return (ret);
}

static int      add_elem(t_lst *lst, int x, int y)
{
    t_lst   tmp;

    tmp = *lst;
    if (!(*lst = new_elem(x, y)))
        return (1);
    (*lst)->next = tmp;
    if (tmp)
        (*lst)->len += tmp->len;
    return (0);
}

static void     free_elem(t_lst *l)
{
    if (!*l)
        return ;
    free_elem(&((*l)->next));
    free(*l);
}

static int      max(double *tab, int len)
{
    int     i;
    double  max;

    for (i = 0, max = tab[0]; i < len; i++)
    {
        if (tab[i] > max)
            max = tab[i];
    }
    return (max);
}

static int      min(double *tab, int len)
{
    int     i;
    double  min;

    for (i = 0, min = tab[0]; i < len; i++)
    {
        if (tab[i] < min)
            min = tab[i];
    }
    return (min);
}

void            level_of_grey_av(Img bitmap)
{
    int     i;
    int     j;
    double  val;

    for (i = 0; i < IMAGE_SIZE_Y; i++)
    {
        for (j = 0; j < IMAGE_SIZE_X; j++)
        {
            val = (bitmap[i][j][0] + bitmap[i][j][1] + bitmap[i][j][2]) / 3;
            bitmap[i][j][0] = val; /* red */
            bitmap[i][j][1] = val; /* green */
            bitmap[i][j][2] = val; /* blue */
        }
    }
}

void            level_of_grey_clearness(Img bitmap)
{
    int     i;
    int     j;
    double  val;

    for (i = 0; i < IMAGE_SIZE_Y; i++)
    {
        for (j = 0; j < IMAGE_SIZE_X; j++)
        {
            val = (max(bitmap[i][j], PIXEL_SIZEOF - 1) + min(bitmap[i][j], PIXEL_SIZEOF - 1)) / 2;
            bitmap[i][j][0] = val; /* red */
            bitmap[i][j][1] = val; /* green */
            bitmap[i][j][2] = val; /* blue */
        }
    }
}

void            level_of_grey_luminance(Img bitmap)
{
    int     i;
    int     j;
    double  val;

    for (i = 0; i < IMAGE_SIZE_Y; i++)
    {
        for (j = 0; j < IMAGE_SIZE_X; j++)
        {
            val = (0.2126 * bitmap[i][j][0]) + (0.7152 * bitmap[i][j][1]) + (0.0722 * bitmap[i][j][2]);
            bitmap[i][j][0] = val; /* red */
            bitmap[i][j][1] = val; /* green */
            bitmap[i][j][2] = val; /* blue */
        }
    }
}

void            tresholding_black_white(Img bitmap)
{
    int     i;
    int     j;
    double  val;

    level_of_grey_luminance(bitmap);
    for (i = 0; i < IMAGE_SIZE_Y; i++)
    {
        for (j = 0; j < IMAGE_SIZE_X; j++)
        {
            if (bitmap[i][j][0] > 0.5)
                val = 1;
            else
                val = 0;
            bitmap[i][j][0] = val; /* red */
            bitmap[i][j][1] = val; /* green */
            bitmap[i][j][2] = val; /* blue */
        }
    }
}

void            more_red(Img bitmap)
{
    int i;
    int j;

    for (i = 0; i < IMAGE_SIZE_Y; i++)
    {
        for (j = 0; j < IMAGE_SIZE_X; j++)
        {
            bitmap[i][j][0] = (1 + bitmap[i][j][0]) / 2; /* red */
        }
    }
}

void            very_more_green(Img bitmap)
{
    int i;
    int j;

    for (i = 0; i < IMAGE_SIZE_Y; i++)
    {
        for (j = 0; j < IMAGE_SIZE_X; j++)
        {
            bitmap[i][j][1] = (3 + bitmap[i][j][1]) / 4; /* green */
        }
    }
}

void            degraded_red_blue_img(Img bitmap)
{
    int     i;
    int     j;
    double  coef;

    for (i = 0; i < IMAGE_SIZE_Y; i++)
    {
        for (j = 0; j < IMAGE_SIZE_X; j++)
        {
            coef = (i + j) / 1024.0;
            bitmap[i][j][0] = (1 - coef) * bitmap[i][j][0]; /* red */
            bitmap[i][j][1] = 0; /* green */
            bitmap[i][j][2] = coef * bitmap[i][j][2]; /* blue */
        }
    }
}

static double  ft_pow(double a, int n)
{
    if (n < 0)
        return (0);
    if (n == 0)
        return (1);
    return (a * ft_pow(a, n - 1));
}

void            middle_light(Img bitmap)
{
    int     i;
    int     j;
    double  coef;

    for (i = 0; i < IMAGE_SIZE_Y; i++)
    {
        for (j = 0; j < IMAGE_SIZE_X; j++)
        {
            coef = ft_pow(1 - (ft_pow(256 - j, 2) + ft_pow(256 - i, 2)) / (2 * ft_pow(256, 2)), 10);
            bitmap[i][j][0] = coef * bitmap[i][j][0]; /* red */
            bitmap[i][j][1] = coef * bitmap[i][j][1]; /* green */
            bitmap[i][j][2] = coef * bitmap[i][j][2]; /* blue */
        }
    }
}

static int      equals(Pix color1, Pix color2)
{
    int     i;

    for (i = 0; i < PIXEL_SIZEOF - 1; i++)
        if (color1[i] - color2[i] != 0)
            return (0);
    return (1);
}

static void     color_copy(Pix color1, Pix color2)
{
    int     i;

    for (i = 0; i < PIXEL_SIZEOF; i++)
        color1[i] = color2[i];
}

void            aux_replace_zone(Img bitmap, int i, int j, Pix color1, Pix color2)
{
    if (i >= IMAGE_SIZE_Y || i < 0 || j < 0 || j >= IMAGE_SIZE_X)
        return ;
    if (equals(bitmap[i][j], color1))
    {
        color_copy(bitmap[i][j], color2);
        if (i > 0)
            aux_replace_zone(bitmap, i - 1, j, color1, color2);
        if (j > 0)
            aux_replace_zone(bitmap, i, j - 1, color1, color2);
        if (i < IMAGE_SIZE_Y - 1)
            aux_replace_zone(bitmap, i + 1, j, color1, color2);
        if (j < IMAGE_SIZE_X - 1)
            aux_replace_zone(bitmap, i, j + 1, color1, color2);
    }
}

void            replace_zone(Img bitmap, int x, int y, Pix color2)
{
    Pix     color1;

    color_copy(color1, bitmap[y][x]);
    if (!equals(color1, color2))
        aux_replace_zone(bitmap, x, y, color1, color2);
}

static double   distance(Pix color1, Pix color2)
{
    return (sqrt(ft_pow(color1[0] - color2[0], 2) + ft_pow(color1[1] - color2[1], 2) + ft_pow(color1[2] - color2[2], 2)));
}

void            average(Img bitmap, Img bitmap1, Img bitmap2)
{
    int i;
    int j;
    int k;

    for (i = 0; i < IMAGE_SIZE_Y; i++)
    {
        for (j = 0; j < IMAGE_SIZE_X; j++)
        {
            for (k = 0; k < PIXEL_SIZEOF; k++)
                bitmap[i][j][k] = (bitmap1[i][j][k] + bitmap2[i][j][k]) / 2.0;
        }
    }
}

static void     init_tab(int tab[IMAGE_SIZE_Y][IMAGE_SIZE_X])
{
    int i;
    int j;

    for (i = 0; i < IMAGE_SIZE_Y; i++)
    {
        for (j = 0; j < IMAGE_SIZE_X; j++)
        {
            tab[i][j] = 0;
        }
    }
}

int         replace_similar(Img bitmap, int x, int y)
{
    Pix     color;
    t_lst   l;
    t_lst   tmp;
    int     tab[IMAGE_SIZE_Y][IMAGE_SIZE_X];
    int     k;
    int     i;
    int     j;
    
    color_copy(color, bitmap[y][x]);
    init_tab(tab);
    if (!(l = new_elem(x, y)))
        return (1);
    for (k = 0; k < l->len; k++)
    {
        i = l->y;
        j = l->x;
        if (!tab[i][j])
        {
            tab[i][j] = 1;
            if (distance(bitmap[i][j], color) < 0.25)
            {
                if (add_elem(&l, j, i))
                    return (1);
                if (i > 0 && !tab[i - 1][j])
                {
                    if (add_elem(&l, j, i - 1))
                        return (1);
                }
                if (j > 0 && !tab[i][j - 1])
                {
                    if (add_elem(&l, j - 1, i))
                        return (1);
                }
                if (i < IMAGE_SIZE_Y - 1 && !tab[i + 1][j])
                {
                    if (add_elem(&l, j, i + 1))
                        return (1);
                }
                if (j < IMAGE_SIZE_X - 1 && !tab[i][j + 1])
                {
                    if (add_elem(&l, j + 1, i))
                        return (1);
                }
            }
        }
    }
    for (tmp = l; tmp; tmp = tmp->next)
        color_copy(bitmap[tmp->y][tmp->x], color);
    free_elem(&l);
    return (0);
}


int         segmentation(Img bitmap)
{
    t_lst   l;
    t_lst   tmp;
    Pix     c;
    int     t[IMAGE_SIZE_Y][IMAGE_SIZE_X];
    int     tab[IMAGE_SIZE_Y][IMAGE_SIZE_X];
    int     x;
    int     y;
    int     i;
    int     j;
    int     k;

    init_tab(t);
    for (y = 0; y < IMAGE_SIZE_Y; y++)
    {
        for (x = 0; x < IMAGE_SIZE_X; x++)
        {
            if (!t[y][x])
            {
                init_tab(tab);
                color_copy(c, bitmap[y][x]);
                if (!(l = new_elem(x, y)))
                    return (1);
                for (k = 0; k < l->len; k++)
                {
                    i = l->y;
                    j = l->x;
                    if (!tab[i][j] && !t[i][j])
                    {
                        tab[i][j] = 1;
                        if (distance(bitmap[i][j], c) < 0.15)
                        {
                            if (add_elem(&l, j, i))
                                return (1);
                            t[i][j] = 1;
                            if (i > 0 && !tab[i - 1][j])
                            {
                                if (add_elem(&l, j, i - 1))
                                    return (1);
                            }
                            if (j > 0 && !tab[i][j - 1])
                            {
                                if (add_elem(&l, j - 1, i))
                                    return (1);
                            }
                            if (i < IMAGE_SIZE_Y - 1 && !tab[i + 1][j])
                            {
                                if (add_elem(&l, j, i + 1))
                                    return (1);
                            }
                            if (j < IMAGE_SIZE_X - 1 && !tab[i][j + 1])
                            {
                                if (add_elem(&l, j + 1, i))
                                    return (1);
                            }
                        }
                    }
                }
                for (tmp = l; tmp; tmp = tmp->next)
                {
                    t[tmp->y][tmp->x] = 1;
                    color_copy(bitmap[tmp->y][tmp->x], c);
                }
                free_elem(&l);
            }
        }
    }
    return (0);
}

void        encoding(Img bitmap, Img bitmap1, Img bitmap2)
{
    int     i;
    int     j;
    int     k;
    double  val;

    for (i = 0; i < IMAGE_SIZE_Y; i++)
    {
        for (j = 0; j < IMAGE_SIZE_X; j++)
        {
            for (k = 0; k < PIXEL_SIZEOF; k++)
            {
                val = bitmap1[i][j][k];
                val = floor(val * 1000) / 1000;
                val = val + bitmap2[i][j][k] / 1000;
                bitmap[i][j][k] = val;
            }
        }
    }
}

void        decoding(Img bitmap)
{
    int     i;
    int     j;
    int     k;
    double  val;

    for (i = 0; i < IMAGE_SIZE_Y; i++)
    {
        for (j = 0; j < IMAGE_SIZE_X; j++)
        {
            for (k = 0; k < PIXEL_SIZEOF; k++)
            {
                val = bitmap[i][j][k];
                val = val * 1000 - floor(val * 1000);
                bitmap[i][j][k] = val;
            }
        }
    }
}

static Pix  **alloc_res(Pix **ret, double factor)
{
    int     i;
    int     j;
    int     k;

    if (!(ret = (Pix**) malloc(sizeof(Pix*) * (int) (IMAGE_SIZE_Y * factor))))
        return (NULL);
    for (i = 0; i < (int) (IMAGE_SIZE_Y * factor); i++)
    {
        if (!(ret[i] = (Pix*) malloc(sizeof(Pix) * (int) (IMAGE_SIZE_X * factor))))
            return (NULL);
        for (j = 0; j < (int) (IMAGE_SIZE_X * factor); j++)
        {
            for (k = 0; k < PIXEL_SIZEOF; k++)
                ret[i][j][k] = 0;
        }
    }
    return (ret);
}

void        enlargement_integer(Pix ***result, Img bitmap, int factor)
{
    int i;
    int j;
    int k;
    int l;

    *result = alloc_res(*result, (double) factor);
    for (i = 0; i < IMAGE_SIZE_Y; i++)
    {
        for (j = 0; j < IMAGE_SIZE_X; j++)
        {
            for (k = 0; k < factor; k++)
            {
                for (l = 0; l < factor; l++)
                {
                    color_copy((*result)[i * factor + k][j * factor + l], bitmap[i][j]);
                }
            }
        }
    }
}

void        enlargement(Pix ***result, Img bitmap, double factor)
{
    int i;
    int j;
    int x;
    int y;
    int len_x;
    int len_y;

    *result = alloc_res(*result, factor);
    for (i = 0, len_y = IMAGE_SIZE_Y * factor; i < len_y; i++)
    {
        for (j = 0, len_x = IMAGE_SIZE_X * factor; j < len_x; j++)
        {
            x = j / factor;
            y = i / factor;
            if (j / factor - x > 0.5 && x < IMAGE_SIZE_X - 1)
                x++;
            if (i / factor - y > 0.5 && y < IMAGE_SIZE_Y - 1)
                y++;
            color_copy((*result)[i][j], bitmap[y][x]);
        }
    }
}

static Pix  **alloc_res_div(Pix **ret, double divisor)
{
    int     i;
    int     j;
    int     k;

    if (!(ret = (Pix**) malloc(sizeof(Pix*) * (int) (IMAGE_SIZE_Y / divisor))))
        return (NULL);
    for (i = 0; i < (int) (IMAGE_SIZE_Y / divisor); i++)
    {
        if (!(ret[i] = (Pix*) malloc(sizeof(Pix) * (int) (IMAGE_SIZE_X / divisor))))
            return (NULL);
        for (j = 0; j < (int) (IMAGE_SIZE_X / divisor); j++)
        {
            for (k = 0; k < PIXEL_SIZEOF; k++)
                ret[i][j][k] = 0;
        }
    }
    return (ret);
}

static void init_pix(Pix p)
{
    int i;

    for (i = 0; i < PIXEL_SIZEOF; i++)
        p[i] = 0;
}

static void add_color(Pix c1, Pix c2)
{
    int i;

    for (i = 0; i < PIXEL_SIZEOF; i++)
        c1[i] += c2[i];
}

void        reduction(Pix ***result, Img bitmap, double divisor)
{
    Pix c_av;
    int i;
    int j;
    int k;
    int l;
    int m;
    int len_x;
    int len_y;

    *result = alloc_res_div(*result, divisor);
    for (i = 0, len_y = IMAGE_SIZE_Y / divisor; i < len_y; i++)
    {
        for (j = 0, len_x = IMAGE_SIZE_X / divisor; j < len_x; j++)
        {
            init_pix(c_av);
            for (k = 0; k < divisor; k++)
            {
                for (l = 0; l < divisor; l++)
                {
                    add_color(c_av,
                        bitmap[(int) (i * divisor + l)][(int) (j * divisor + k)]);
                }
            }
            for (m = 0; m < PIXEL_SIZEOF; m++)
                c_av[m] = c_av[m] / ft_pow(divisor, 2);
            color_copy((*result)[i][j], c_av);
        }
    }
}
