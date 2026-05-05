# XML Tag Validator using Stack (C Language)

## Overview
This program checks whether an XML file has correct opening and closing tags using a stack data structure.

## Features
- Reads XML file
- Checks matching tags
- Uses stack (linked list implementation)
- Displays Valid or Invalid XML

---

## How It Works
1. The program opens and reads the file `note.xml`.
2. It reads the file character by character.
3. When it finds `<`, it starts reading a full tag until `>` is found.
4. The extracted tag is stored in a string.
5. If the tag is an opening tag (example: `<a>`):
   - It is pushed into the stack.
6. If the tag is a closing tag (example: `</a>`):
   - The program pops the top element from the stack.
   - It compares both tags (opening and closing).
7. If they match, the program continues.
8. If they do not match, the XML is invalid.
9. After finishing the file:
   - If the stack is empty → XML is valid
   - If the stack is not empty → XML is invalid

---

## How to Run

### Compile
gcc main.c -o xml_validator

### Run
./xml_validator

### Input File
Create a file named `note.xml` in the same folder.

Example:
<a>
  <b></b>
</a>

---

## Output
Valid XML  
or  
Invalid XML

---

## Limitations
- Does not support attributes like `<a id="1">`
- Does not support self-closing tags like `<br/>`
- Fixed tag size in memory

---

## Conclusion
This program uses a stack to ensure correct XML tag structure by matching opening and closing tags in the correct order.
