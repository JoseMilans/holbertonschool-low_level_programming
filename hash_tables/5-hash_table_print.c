#include "hash_tables.h"
/**
 * hash_table_print - prints a hash table
 * @ht: hash table to print
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int index;
	hash_node_t *current;
	int comma_flag = 0;

	if (!ht)
		return;
	printf("{");
	for (index = 0; index < ht->size; index++)
	{
		current = ht->array[index];
		while (current)
		{
			if (comma_flag)
				printf(", ");
			printf("'%s': '%s'", current->key, current->value);
			comma_flag = 1;
			current = current->next;
		}
	}
	printf("}\n");
}
