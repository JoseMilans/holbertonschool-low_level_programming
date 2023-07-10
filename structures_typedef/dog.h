#ifndef DOG_H
#define DOG_H
/**
 * struct dog - Represents a dog with its name, age and owner.
 * @name: Dog's name.
 * @age: Dog's age.
 * @owner: Dog's owner.
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};
typedef struct dog dog_t;
int _putchar(char c);
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);
#endif

