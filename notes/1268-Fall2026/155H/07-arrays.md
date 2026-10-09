
# CSCE 155H - Computer Science I - Honors
## Arrays & Collections
### Fall 2026

* Almost never deal with just one piece of data
* Instead you deal with *collections* of data
* Both C and Java support old-school *arrays* collections of *similar* things (things of the same type: `int`, `double`, etc.) all stored *contiguously*
* In general:
  * Arrays have a single *identifier* (variable name)
  * You can access individual *elements* in an array using an *index*
  * The first element is always at index `0`
  * YOu use square brackets to access each element
  * ex: first is at `arr[0]`, second: `arr[1]`, last (assuming there are `n` elements) is at `arr[n-1]`

## Arrays in C

### Static Arrays

* "static" means that they have a fixed size and are created and stored on the program's *stack*
* Static arrays are **extremely limited**
* Since static arrays are allocated on the stack, they exist inside stack frames, those stack frames are destroyed when the function returns
* Stack space is *extremely limited*: it could be 4MB, 8MB or even (embedded systems) limited to kilobytes
* You cannot fit even a "small" array on the stack
* In Java: static arrays are NOT EVEN POSSIBLE!

```c
    //static array declaration:
    int arr[10];
    //creates an array of integers of size 10
    arr[0] = 42;
    arr[1] = 120;
    arr[9] = 12;

    for(int i=0; i<10; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    //Observation: there are no default values in an array, most values will be garbage/DEADBEEF

    //what happens if we get too big...
    int brr[10000000];
    brr[0] = 42;
    brr[9999999] = 101;

    printf("First: %d, last: %d\n", brr[0], brr[999999]);

```

## Dynamic Arrays

* Dynamic arrays are allocated not on the stack but on the *heap*
  * Much larger
  * Less organized
  * Less efficient (in some ways)
* In C: you allocate memory on the heap by asking the OS = Operating System for a "chunk" of memory (however big you need)
* For example:
  * Want to store 10 million integers
  * We would ask for 40 million bytes (4 bytes each `int`)
* You use the function called `malloc` = *m*emory *alloc*ation
* Malloc:
  * Signature: `void * malloc(size_t n)`
  * Think of `size_t` as an integer (the number of bytes you wish to allocate)
  * The return type is a *generic void pointer*: a pointer that can point to anything
  * Its just generic: it points to a generic memory location
  * The returned memory can be used for whatever you want it to be
  * Generally when we receive the pointer, we'll *cast* it as the type that we intend to use it as
  * In any error event, `malloc` will return `NULL`

## Java

* No pointers in Java, no static arrays
* All arrays are allocated on the heap

```java

		//create a "dynamic" array:
		//holds 10 integers
		//all initialized to 0
		int arr[] = new int[10];

		//this same syntax can be used in both languages:
		int primes[] = {2, 3, 5, 7, 11, 13, 17};

		for(int i=0; i<arr.length; i++) {
			System.out.printf("arr[%d] = %d\n", i, arr[i]);
		}

		//enhanced for loop:
		//for each x in the collection primes
		for(int x : primes) {
			System.out.println(x);
		}
```

* Arrays suck, don't use them unless you *have* to
* Java has much better *dynamic* collections
* Java has classes to support `List`s, `Set`s and `Map`s
* A Java `List` is a collection of *ordered* elements that allow duplicates

```java

		//List is a collection of:
		// ordered elements
		// that allows duplicates
		List<Integer> numbers = new ArrayList<>();
		//add always adds the element to the end of the list
		numbers.add(10);
		numbers.add(20);
		numbers.add(30);

		//only integers for this list:
		//numbers.add(10.5);
		//numbers.add("Hello");
		//duplicates are okay:
		numbers.add(10);
		System.out.println(numbers);

		//you can add at an arbitrary index:
		numbers.add(0, 42);
		System.out.println(numbers);

		numbers.add(2, 101);		
		System.out.println(numbers);

		numbers.add(0, 123);
		System.out.println(numbers);

		//you can remove stuff:
		int removedElement = numbers.remove(0);
		System.out.println(numbers);

		//retrieval:
		//get the first element:
		int x = numbers.get(0);
		System.out.println(x);

		//iterate:
		for(int i=0; i<numbers.size(); i++) {
			int y = numbers.get(i);
			System.out.println(y);
		}

		//enhanced for loop:
		for(int z : numbers) {
			System.out.println(z);
		}
```

* A `Set` is an *unordered* collection of *unique* elements

```java

		Set<String> names = new HashSet<>();

		names.add("Chris");
		names.add("Seiya");
		names.add("Jane");
		names.add("Chris");

		System.out.println(names);

		//unordered: there is no first element to get...
		//String name = names.get(0);

		//enhanced for loop is your option
		for(String name : names) {
			System.out.println(name);
		}

//		names.remove("Jane");
//		System.out.println(names);
//		//remove everything:
//		names.clear();
//		System.out.println(names);
//		//size of the set:
//		int n = names.size();

		//transform names to a list:
		List<String> namesList = new ArrayList<>(names);
		System.out.println(names);
		System.out.println(namesList);
		namesList.add("Chris");
		System.out.println(namesList);

		List<Integer> values = new ArrayList<>();
		values.add(10);
		values.add(10);
		values.add(20);
		values.add(30);

		Set<Integer> uniqueValues = new HashSet<>(values);
		System.out.println(uniqueValues);
```

* `Map`s are even better
* Lists: you use 0-indexing: they are all integers and they run 0 up to n - 1
* Sets: no indexing at all, just a "bag" of stuff
* Maps: key-value pairing data structure
* You can map any type to any type

```java

		Map<Integer, String> nuidToName = new HashMap<>();

		nuidToName.put(35140602, "Bourke");
		nuidToName.put(123, "Jones");
		nuidToName.put(987, "Doe");

		System.out.println(nuidToName);

		nuidToName.put(987, "Foo");
		System.out.println(nuidToName);

		//retrieve:		
		String me = nuidToName.get(35140602);
		System.out.println(me);
		String joe = nuidToName.get(456);
		System.out.println(joe);

		nuidToName.put(1111111, "Bourke");

		System.out.println(nuidToName);

		//iterate over a map:
		Set<Integer> keys = nuidToName.keySet();
		for(Integer key : keys) {
			String value = nuidToName.get(key);
			System.out.println(key + " maps to " + value);
		}
```


```text












```
