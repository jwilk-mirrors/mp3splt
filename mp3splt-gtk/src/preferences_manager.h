/**********************************************************
 *
 * mp3splt-gtk -- utility based on mp3splt,
 *                for mp3/ogg splitting without decoding
 *
 * Copyright (c) 2005-2012 Alexandru Munteanu - io_fx@yahoo.fr
 *
 * http://mp3splt.sourceforge.net/
 *
 *********************************************************/

/**********************************************************
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307,
 * USA.
 *
 *********************************************************/

#ifndef PREFERENCES_MANAGER_H

typedef struct {
  gchar* main_key;
  gchar* second_key;
  gint default_value;
  GtkWidget *spinner;
  void (*update_spinner_value_cb)(GtkWidget *spinner, gpointer data);
} spinner_int_preference;

typedef struct {
  GArray *spinner_int_preferences;
} preferences_state;

gchar *get_preferences_filename();
void load_preferences();
void save_preferences(GtkWidget *widget, gpointer data);
void write_default_preferences_file();
void check_pref_file();

void set_language();

preferences_state *pm_state_new();
void pm_free(preferences_state **pm);

void pm_register_spinner_int_preference(gchar *main_key, gchar *second_key,
    gint default_value, GtkWidget *spinner,
    void (*update_spinner_value_cb)(GtkWidget *spinner, gpointer data),
    preferences_state *pm);

void pm_load(GKeyFile *key_file, preferences_state *pm);
void pm_save(GKeyFile *key_file, preferences_state *pm);
void pm_write_default(GKeyFile *key_file, preferences_state *pm);

#define PREFERENCES_MANAGER_H
#endif

