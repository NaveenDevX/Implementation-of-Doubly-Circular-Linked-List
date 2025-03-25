# 📌 Doubly Circular Linked List in C  

This project implements a **Doubly Circular Linked List** in C, allowing operations such as insertion, deletion, and display.  
A **Doubly Circular Linked List** is a variation of a **Doubly Linked List**, where the last node’s `next` pointer links back to the first node, forming a circular structure.

---

## 📜 Table of Contents  

- [Features](#-features)  
- [Concept](#-concept-of-doubly-circular-linked-list)  
- [File Structure](#-file-structure)  
- [Installation & Usage](#-installation--usage)  
- [Example Execution](#-example-execution)  
- [Code Overview](#-code-overview)  
- [Contributing](#-contributing)  
- [License](#-license)  

---

## 🔹 Features  

✅ Create a doubly circular linked list dynamically.  
✅ Display all elements in the list.  
✅ Insert elements at the **beginning** or **end**.  
✅ Delete elements from the **beginning**, **end**, or a **specific node**.  
✅ Delete the entire list to **free memory**.  

---

## 🔍 Concept of Doubly Circular Linked List  

A **Doubly Circular Linked List** is a type of **linked list** where:  
1. Each **node** contains three fields:  
   - A **pointer to the next node**  
   - A **pointer to the previous node**  
   - A **data value**  
2. The **last node’s next pointer** points to the **first node** (circular).  
3. The **first node’s previous pointer** points to the **last node**.  

💡 **Advantages**:  
- It allows **traversal in both directions** (forward & backward).  
- Circular behavior helps in applications like **round-robin scheduling**.  

---

## 📂 File Structure  

