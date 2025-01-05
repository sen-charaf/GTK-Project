#ifndef MENU_ITEM_H
#define MENU_ITEM_H

#include "./../../global.h"

#define MAX_LABEL_SIZE 50
#define MAX_ACCEL_PATH_SIZE 100

/*  default values */
#define DEFAULT_MENU_ITEM_DIMENSIONS \
    {                                \
        .height = 0,                 \
        .width = 0}

#define DEFAULT_MENU_ITEM_MARGIN \
    {                            \
        .bottom = 0,             \
        .top = 0,                \
        .start = 0,              \
        .end = 0}

#define DEFAULT_MENU_ITEM                           \
    {                                               \
        .label = "\0",                              \
        .accel_path = "\0",                         \
        .reserve_indicator = FALSE,                 \
        .use_underline = FALSE,                     \
        .right_justified = FALSE,                   \
        .tooltip = "\0",                            \
        .dimensions = DEFAULT_MENU_ITEM_DIMENSIONS, \
        .margins = DEFAULT_MENU_ITEM_MARGIN,        \
        .bg_color = "\0",                           \
        .text_color = "\0"}
// .margin = DEFAULT_MENU_ITEM_MARGIN,

typedef struct
{
    gchar label[MAX_LABEL_SIZE];           // Add simple label
    gchar accel_path[MAX_ACCEL_PATH_SIZE]; // Add accel path (keyboard shortcuts)
    gboolean reserve_indicator;
    gboolean use_underline; // Associate to the parent screen or else
    gboolean right_justified;
    gchar tooltip[MAX_TOOLTIP_SIZE];
    Dimensions dimensions;
    Margins margins;
    gchar bg_color[MAX_COLOR_SIZE];
    gchar text_color[MAX_COLOR_SIZE];

} MenuItemConfig;

MenuItemConfig *init_menu_item_config(const gchar *label, gboolean is_group);

GtkWidget *create_menu_item(MenuItemConfig menu_item_config);

void menu_item_set_group(GtkWidget *widget, GtkWidget *group);

#endif