<h1 align="center">
<img src="https://github.com/mcombeau/mcombeau/blob/main/42_badges/push_swape.png" alt="Push_swap 42 project badge"/>
<br>push_swap</h1>
<h3>◦ An efficient sorting algorithm using 2 stacks </h3>

---

## 📖 Table of Contents
- [📍 Overview 📍](#-overview-)
- [📍 Rules 📍](#-rules-)
- [🔎 What is implemented?](#-what-is-implemented)
- [🚀 Getting Started](#-getting-started--)
    - [🔧 Installation](#-installation)
    - [🤖 Use push_swap](#-use-push_swap)
- [Extra: Check out my profile on the Intranet](#--check-out-my-profile-on-the-intra-of-42-school-%EF%B8%8F)

---

## 📍 Overview 📍

This project is about sorting numbers with a limited number of movements and using 2 stacks.


---

## 📍 Rules 📍

The functions have to follow a strict rule. For example, you cannot intitialize a variable in the line where you declare it.


---


## 🔎 _What is implemented?_

➤ These are the movements can be used:

* pa ➡️ (push A): Take the first element at the top of B and put it at the top of A. Do nothing if B is empty.
* pb ➡️ (push B): Take the first element at the top of A and put it at the top of B. Do nothing if A is empty.
* sa ➡️ (swap A): Swap the first 2 elements at the top of stack A. Do nothing if there is only one or no elements.
* sb ➡️ (swap B): Swap the first 2 elements at the top of stack B. Do nothing if there is only one or no elements.
* ss ➡️ sa and sb at the same time.
* ra ➡️ (rotate A): Shift all elements of stack A up by 1. The first element becomes the last one.
* rb ➡️ (rotate B): Shift all elements of stack B up by 1. The first element becomes the last one.
* rr ➡️ ra and rb at the same time.
* rra ➡️ (reverse rotate A): Shift all elements of stack A down by 1. The last element becomes the first one.
* rrb ➡️ (reverse rotate B): Shift all elements of stack b down by 1. The last element becomes the first one.
* rrr ➡️ : rra and rrb at the same time.

➤ These are the limited number of movements the program can execute:

* Sorting 3 values: no more than 3 actions.
* Sorting 5 values: no more than 12 actions.
* Sorting 100 values: rating from 1 to 5 points depending on the number of actions:
  * 5 points for less than 700 actions
  * 4 points for less than 900
  * 3 points for less than 1100
  * 2 points for less than 1300
  * 1 point for less than 1500
* Sorting 500 values: rating from 1 to 5 points depending on the number of actions:
  * 5 points for less than 5500 actions
  * 4 points for less than 7000
  * 3 points for less than 8500
  * 2 points for less than 10000
  * 1 point for less than 11500

---

## 🚀 Getting Started  🚀 

### 🔧 Installation

1. Clone the Printf_Implementation repository:
```sh
git clone https://github.com/rcortes-b/push_swap.git
```

2. Change to the project directory:
```sh
cd push_swap
```

3. Compile the dependencies to get the program:
```sh
make
```

### 🤖 Use push_swap
Once the program is obtained you can test it:
```sh
./push_swap <numbers_to_insert>
```
### - Check out my profile on the intra of 42 school ↙️
[https://profile.intra.42.fr/users/rcortes-]

---

[**Return**](#Top)

---
