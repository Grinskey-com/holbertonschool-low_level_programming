C - Hash Tables
A lightweight C implementation of a hash table utilizing the DJB2 hashing algorithm and separate chaining for collision resolution.

How It Works
Hash tables provide O(1) average lookup, insertion, and deletion times by mapping arbitrary string keys directly to array indices through a deterministic math pipeline:
Character Processing: Converts string characters into their numerical ASCII values.
Hash Computation: Runs characters through the DJB2 algorithm using a initial seed of 5381 and compounding factor 33 (hash * 33 + c).
Index Bounding: Applies the modulo operator (hash % size) to compress massive hash integers into valid array index boundaries (0 to size - 1).
Collision Handling: Handles index collisions by prepending new items to a singly linked list at each array bucket in O(1) time.
