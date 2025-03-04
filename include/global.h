#ifndef GLOBAL_H
#define GLOBAL_H
#include <gtk/gtk.h>
#include <stdbool.h>
#include <stdlib.h>

#include "./constants.h"

/* Global macros  */

// check if the pointer is not null
#define SAFE_ALLOC(ptr, type, length)                           \
    do                                                          \
    {                                                           \
        ptr = (type *)g_malloc(length * sizeof(type));          \
        if (!ptr)                                               \
        {                                                       \
            g_critical("Failed to allocate memory for " #type); \
        }                                                       \
    } while (0)

#define IS_EXISTE(pointer)                      \
    do                                          \
    {                                           \
        if (!pointer)                           \
        {                                       \
            g_critical(#pointer " not exist."); \
            return NULL;                        \
        }                                       \
    } while (0)

#define MAX_TAG_SIZE 50
#define MAX_VIEW_ID_SIZE 50
#define PARAM_COUNT 4

#define SET_VIEW_CONFIG_PROPERTY(property, value, view_config)                      \
    if (g_strcmp0(property, "position_x") == 0)                                     \
    {                                                                               \
        view_config->position_x = atoi(value);                                      \
    }                                                                               \
    if (g_strcmp0(property, "position_y") == 0)                                     \
    {                                                                               \
        view_config->position_y = atoi(value);                                      \
    }                                                                               \
    if (g_strcmp0(property, "pack_direction") == 0)                                 \
    {                                                                               \
        view_config->pack_direction = atoi(value);                                  \
    }                                                                               \
    if (g_strcmp0(property, "box_expand") == 0)                                     \
    {                                                                               \
        view_config->box_expand = g_strcmp0(value, "true") == 0 ? TRUE : FALSE;     \
    }                                                                               \
    if (g_strcmp0(property, "box_fill") == 0)                                       \
    {                                                                               \
        view_config->box_fill = g_strcmp0(value, "true") == 0 ? TRUE : FALSE;       \
    }                                                                               \
    if (g_strcmp0(property, "tab_label") == 0)                                      \
    {                                                                               \
        g_strlcpy(view_config->tab_label, value, MAX_LABEL_SIZE);                   \
    }                                                                               \
    if (g_strcmp0(property, "box_padding") == 0)                                    \
    {                                                                               \
        view_config->box_padding = atoi(value);                                     \
    }                                                                               \
    if (g_strcmp0(property, "flow_box_order") == 0)                                 \
    {                                                                               \
        view_config->flow_box_order = atoi(value);                                  \
    }                                                                               \
    if (g_strcmp0(property, "paned_order") == 0)                                    \
    {                                                                               \
        view_config->paned_order = atoi(value);                                     \
    }                                                                               \
    if (g_strcmp0(property, "is_reorderable") == 0)                                 \
    {                                                                               \
        view_config->is_reorderable = g_strcmp0(value, "true") == 0 ? TRUE : FALSE; \
    }                                                                               \
    if (g_strcmp0(property, "row") == 0)                                            \
    {                                                                               \
        view_config->row = atoi(value);                                             \
    }                                                                               \
    if (g_strcmp0(property, "column") == 0)                                         \
    {                                                                               \
        view_config->column = atoi(value);                                          \
    }                                                                               \
    if (g_strcmp0(property, "row_span") == 0)                                       \
    {                                                                               \
        view_config->row_span = atoi(value);                                        \
    }                                                                               \
    if (g_strcmp0(property, "column_span") == 0)                                    \
    {                                                                               \
        view_config->column_span = atoi(value);                                     \
    }                                                                               \
    if (g_strcmp0(property, "onclick") == 0)                                        \
    {                                                                               \
        g_strlcpy(view_config->onclick, value, MAX_SIGNAL_NAME_SIZE);               \
    }                                                                               \
    if (g_strcmp0(property, "on_active") == 0)                                      \
    {                                                                               \
        g_strlcpy(view_config->on_active, value, MAX_SIGNAL_NAME_SIZE);             \
    }                                                                               \
    if (g_strcmp0(property, "param_1") == 0)                                        \
    {                                                                               \
        g_strlcpy(view_config->param[0], value, MAX_SIGNAL_NAME_SIZE);              \
    }                                                                               \
    if (g_strcmp0(property, "param_2") == 0)                                        \
    {                                                                               \
        g_print("r\n\nead param_2:%s", value);                                      \
        g_strlcpy(view_config->param[1], value, MAX_SIGNAL_NAME_SIZE);              \
    }                                                                               \
    if (g_strcmp0(property, "param_3") == 0)                                        \
    {                                                                               \
        g_strlcpy(view_config->param[2], value, MAX_SIGNAL_NAME_SIZE);              \
    }                                                                               \
    if (g_strcmp0(property, "param_4") == 0)                                        \
    {                                                                               \
        g_strlcpy(view_config->param[3], value, MAX_SIGNAL_NAME_SIZE);              \
    }                                                                               \
    if (g_strcmp0(property, "menu_orientation") == 0)                               \
    {                                                                               \
        g_strlcpy(view_config->menu_orientation, value, MAX_SIGNAL_NAME_SIZE);      \
    }                                                                               \
    if (g_strcmp0(property, "menu_top") == 0)                                       \
    {                                                                               \
        view_config->menu_top = atoi(value);                                        \
    }                                                                               \
    if (g_strcmp0(property, "menu_bottom") == 0)                                    \
    {                                                                               \
        view_config->menu_bottom = atoi(value);                                     \
    }                                                                               \
    if (g_strcmp0(property, "menu_left") == 0)                                      \
    {                                                                               \
        view_config->menu_left = atoi(value);                                       \
    }                                                                               \
    if (g_strcmp0(property, "menu_right") == 0)                                     \
    {                                                                               \
        view_config->menu_right = atoi(value);                                      \
    }

#define DFEAULT_VIEW_CONFIG(view_config)                                    \
    do                                                                      \
    {                                                                       \
        view_config->position_x = 0;                                        \
        view_config->position_y = 0;                                        \
        view_config->pack_direction = 1;                                    \
        view_config->box_expand = FALSE;                                    \
        view_config->box_fill = FALSE;                                      \
        view_config->box_padding = 0;                                       \
        view_config->group = NULL;                                          \
        view_config->view_id[0] = '\0';                                     \
        view_config->tab_label[0] = '\0';                                   \
        view_config->is_reorderable = TRUE;                                 \
        view_config->row = 0;                                               \
        view_config->column = 0;                                            \
        view_config->row_span = 1;                                          \
        view_config->column_span = 1;                                       \
        view_config->onclick[0] = '\0';                                     \
        view_config->on_active[0] = '\0';                                   \
        strcpy(view_config->menu_orientation, "vertical");                  \
        view_config->menu_top = 0;                                          \
        view_config->menu_bottom = 1;                                       \
        view_config->menu_left = 0;                                         \
        view_config->menu_right = 0;                                        \
        for (int i = 0; i < PARAM_COUNT; view_config->param[i++][0] = '\0') \
            ;                                                               \
    } while (0);

typedef struct
{
    gchar view_id[MAX_VIEW_ID_SIZE];

    // Fixed container
    int position_x;
    int position_y;

    // Box container
    int pack_direction;
    gboolean box_expand;
    gboolean box_fill;
    int box_padding;

    // FlowBox container
    gint flow_box_order;

    // Paned container
    // add1: 0 or add2: 1
    gint paned_order;

    // Ex: radio button
    GtkWidget *group;

    // NoteBook container properties
    // tab label in Notebook container
    gchar tab_label[MAX_LABEL_SIZE];
    gboolean is_reorderable;

    // Grid container properties
    gint row;
    gint column;
    gint row_span;
    gint column_span;

    // Signals
    gchar onclick[MAX_SIGNAL_NAME_SIZE];   // Path to the icon image file
    gchar on_active[MAX_SIGNAL_NAME_SIZE]; // Path to the icon image file
    // Params of Signals
    gchar param[PARAM_COUNT][MAX_SIGNAL_NAME_SIZE]; // First function parameter

    gchar menu_orientation[MAX_LABEL_SIZE];
    gint menu_top;
    gint menu_bottom;
    gint menu_left;
    gint menu_right;

} ViewConfig;

typedef struct VIEW
{
    GtkWidget *widget;
    struct VIEW *parent;
    struct VIEW *child;
    struct VIEW *next;
    ViewConfig *view_config;
} View;

extern View *root_view_gloabl;
extern View *root_dialog_view_global;

// We should rename this from global to core wich means system libs and has more signification

/**
 * @brief global structure for windget (window, button, label, ...)
 * Dimension of widget, the height and width of widget. for each widget have default value for this structure (macros value)
 */
/**
 * @brief Structure to hold the dimensions of a widget
 */
typedef struct
{
    gint width;  /**< Width of the widget */
    gint height; /**< Height of the widget */
} Dimensions;

/**
 * @brief Structure to hold the margins of a widget
 */
typedef struct
{
    gint top;    /**< Top margin */
    gint bottom; /**< Bottom margin */
    gint start;  /**< Start margin */
    gint end;    /**< End margin */
} Margins;

/* inline function */

/**
 * @brief free widget memory space
 * @param widget that will destroy it
 * @return void
 */
// inline void free_widget(GtkWidget *widget);

/* Global functions */
/**
 * @brief This function init the style provider context that hold the css code and apply it in the screen
 * @param widget the widget that we want apply the style on it
 * @param bg_color the background color will be applyed on the widget
 * @param color the color of label text that will be applyed on the widget
 * @param bg_image the background image name of the widget
 * @return GtkStyleContext pointer
 */
GtkStyleContext *get_style_provider_context(GtkWidget *widget, const gchar *bg_color, const gchar *color, const gchar *bg_image);

/**
 * @brief This function gives a background and text color to a widget
 * @param widget Widget cible
 * @param bg_color The background color
 * @param color The text color
 * @return void
 */
void widget_set_colors(GtkWidget *widget, const gchar *bg_color, const gchar *color);

/**
 * @brief This function gives a background image to a widget
 * @param widget Widget cible
 * @param bg_image The background image name
 * @param color The text color
 * @return void
 */
void widget_set_background_image(GtkWidget *widget, const gchar *bg_image, const gchar *color);

/**
 * @brief This function gives a background image to a widget without using css
 * @param widget Widget cible
 * @param bg_image The background image name
 * @return void
 */
void widget_set_background_image_without_css(GtkWidget *widget, const gchar *bg_image);

/**
 * @brief This function add margins to a widget
 * @param widget Widget cible
 * @param top The top margin
 * @param bottom The bottom margin
 * @param start The left margin
 * @param end The right margin
 * @return void
 */
void widget_set_margins(GtkWidget *widget, Margins margins);

/**
 * @brief This function set the text color of a widget
 * @param widget Widget cible
 * @param color The text color
 * @param state The state of the widget (ex: GTK_STATE_FLAG_NORMAL, GTK_STATE_FLAG_ACTIVE, ...)
 * @return void
 */
// void widget_set_background_color(GtkWidget *widget, const gchar *color, GtkStateFlags state);

/**
 * @brief This function set the text color of a widget
 * @param widget Widget cible
 * @param color The text color
 * @param state The state of the widget (ex: GTK_STATE_FLAG_NORMAL, GTK_STATE_FLAG_ACTIVE, ...)
 * @return void
 */
// void widget_set_text_color(GtkWidget *widget, const gchar *color, GtkStateFlags state);

/**
 * @brief This function set the font of a widget
 * @param widget Widget cible
 * @param font_name The font name or family (ex: "Arial, SansSerif")
 * @param font_size The font size
 * @return void
 */
void widget_set_font_size(GtkWidget *widget, int size);

// TODO: Should be not manipulate the end of tag ">" in the file
// TODO: Should manipulate spaces and tabs and new lines
gchar *read_property(FILE *index, int *status);

// Ignore space within the value
gchar *read_value(FILE *index, int *status);

gboolean is_character(gchar c);

/**
 * @typedef ConfigurePropertyCallback
 * @brief A callback function type for configuring properties.
 *
 * This callback function is used to configure specific properties
 * for a given configuration type.
 *
 * @param config A pointer to the specific configuration structure.
 * @param view_config A pointer to the ViewConfig structure.
 * @param property The property name as a string.
 * @param value The property value as a string.
 * @return A pointer to the updated ViewConfig structure.
 */
typedef ViewConfig *(*ConfigurePropertyCallback)(void *config, ViewConfig *view_config, gchar *property, gchar *value);

/**
 * @brief Initialize a generic configuration using a callback function.
 *
 * This function reads properties and their values from the provided file index
 * and uses the callback function to configure the specific properties for
 * the given configuration.
 *
 * @param index The file pointer to the configuration index file.
 * @param config A pointer to the specific configuration structure.
 * @param configure_property_callback The callback function to configure properties.
 * @return A pointer to the initialized ViewConfig structure, or NULL on failure.
 */
ViewConfig *init_generic_config(FILE *index, void *config, ConfigurePropertyCallback configure_property_callback);
/**
 * @brief Set the fixed size of a widget.
 * @param widget The GtkWidget to resize.
 * @param dimensions The dimensions structure containing width and height.
 */
void set_widget_size(GtkWidget *widget, Dimensions dimensions);

/**
 * @brief function to constrole font family
 * @param widget The widget to change font
 * @param font_family a string indicate the font family
 *
 * here a list of font family example:
 * 1.   "Arial"
 * 2.   "Courier New"
 * 3.   "Times New Roman"
 * 4.   "Comic Sans MS"
 * 5.   "Verdana"
 */
void widget_set_font_family(GtkWidget *widget, const char *font_family);

/**
 * @brief Finds a view by its ID in a graph of views.
 *
 * This function searches for a view with the specified ID in a graph of views.
 * Each node in the graph contains pointers to its child and next (sibling) views.
 *
 * @param view_id The ID of the view to find.
 * @param root_view The root view of the graph to start the search from.
 * @return A pointer to the view with the specified ID, or NULL if not found.
 */
View *find_view_by_id(char *view_id, View *root_view);

#endif
