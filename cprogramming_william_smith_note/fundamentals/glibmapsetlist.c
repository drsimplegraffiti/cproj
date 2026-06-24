#include <glib.h>
#include <glib/gprintf.h>

int main() {
  // ------------------------------
  // 1. GLib List (doubly-linked list)
  // ------------------------------
  GList *list = NULL;

  // Append elements to the list
  list = g_list_append(list, "Hello");
  list = g_list_append(list, "World");

  // Iterate and print list elements
  g_printf("List elements: ");
  for (GList *iter = list; iter != NULL; iter = iter->next) {
    g_printf("%s ", (char *)iter->data);
  }
  g_printf("\n");

  // Find an element in the list
  GList *element = g_list_find_custom(list, "World", (GCompareFunc)g_strcmp0);
  if (element != NULL) {
    g_printf("Found element: %s\n", (char *)element->data);
  }

  // Update an element
  element->data = "GLib";

  // Remove an element
  list = g_list_remove(list, "Hello");

  // Print updated list
  g_printf("Updated list: ");
  for (GList *iter = list; iter != NULL; iter = iter->next) {
    g_printf("%s ", (char *)iter->data);
  }
  g_printf("\n");

  // Free the list memory
  g_list_free(list);

  // ------------------------------
  // 2. GLib Set (using GHashTable)
  // ------------------------------
  GHashTable *set = g_hash_table_new(g_str_hash, g_str_equal);

  // Add elements to the set
  g_hash_table_add(set, "Hello");
  g_hash_table_add(set, "World");

  // Check if an element exists
  gboolean exists = g_hash_table_contains(set, "Hello");
  g_printf("Hello %s in the set\n", exists ? "exists" : "does not exist");

  // Remove an element
  g_hash_table_remove(set, "Hello");

  // Check again
  exists = g_hash_table_contains(set, "Hello");
  g_printf("Hello %s in the set\n", exists ? "exists" : "does not exist");

  // Destroy the set
  g_hash_table_destroy(set);

  // ------------------------------
  // 3. GLib Map (key-value pairs using GHashTable)
  // ------------------------------
  GHashTable *map = g_hash_table_new(g_str_hash, g_str_equal);

  // Insert key-value pairs
  g_hash_table_insert(map, "apple", GINT_TO_POINTER(1));
  g_hash_table_insert(map, "banana", GINT_TO_POINTER(2));

  // Lookup a key
  int value = GPOINTER_TO_INT(g_hash_table_lookup(map, "banana"));
  g_printf("The value of banana is %d\n", value);

  // Update the value
  g_hash_table_insert(map, "banana", GINT_TO_POINTER(3));
  value = GPOINTER_TO_INT(g_hash_table_lookup(map, "banana"));
  g_printf("The updated value of banana is %d\n", value);

  // Remove a key
  g_hash_table_remove(map, "apple");

  // Check if key exists
  exists = g_hash_table_contains(map, "apple");
  g_printf("Apple %s in the map\n", exists ? "exists" : "does not exist");

  // Destroy the map
  g_hash_table_destroy(map);

  return 0;
}

// ```bash sudo apt update
// sudo apt install libglib2.0-dev pkg-config
// gcc glibmapsetlist.c -o glibmapsetlist $(pkg-config --cflags --libs glib-2.0)
// ```
