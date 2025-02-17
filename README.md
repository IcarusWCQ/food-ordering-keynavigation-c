# 🍔 Food Ordering System with Key Navigation in C

## 📌 **⚠️ This project was developed as part of a University Assignment. ⚠️**
This project was created as part of a university coursework assignment, focusing on **interactive console-based application development** using C. The goal was to implement **user-friendly navigation, structured billing, and payment processing** while enhancing the interface with **ASCII art** for a more engaging experience.

## 📌 Description
This is a **terminal-based food ordering system** written in C, featuring an interactive **menu controlled via arrow keys** instead of manual number inputs. The system allows users to:

✅ Navigate the main menu  
✅ Select food items  
✅ Review orders  
✅ Proceed with payments seamlessly  

---

## ✨ Features
🔹 **ASCII Art UI** – Uses ASCII art to enhance visual presentation and make the terminal interface more appealing 🎨  
🔹 **Arrow Key Navigation** – Move through the menu using **Up/Down Arrow keys**, confirm with **Enter**  
🔹 **Real-time Order Processing** – Add, modify, and confirm orders dynamically  
🔹 **Structured Billing System** – Auto-generates a **bill with token numbers** for tracking  
🔹 **Payment System** – **Calculates total cost** and provides a **detailed change breakdown**  
🔹 **Receipt Generation** – Prints a **detailed receipt** after successful payment  
🔹 **Console-Based Interface** – Displays **formatted text menus and bills**  

---

## 🚀 How to Run
### 🔹 Compile the Program:
```sh
gcc foodordering.c -o food_ordering.exe
```
### 🔹 Run the Executable:
```sh
food_ordering.exe
```

---

## 🎮 Controls
🎯 **Arrow Up/Down** – Move between menu options  
🎯 **Enter** – Select an option  

---

## 📜 Example Main Page Output:
```
 _________________________________________________________________________________________________________________
/                                                                                                                 \
|                         Welcome To Warung Le Familia!!                                                          |
|       _..----.._                                                                               |\ /| /|_/|      |
|     .'     o    '.      We are thrilled to welcome you to our gastronomic haven,              |\||-|\||-/|/|    |
|    /   o       o  \     where passion and flavor collide in perfecr harmony.                   \\|\|//||///     |
|   |o        o     o|    As you cross our threshold, pepare to embark on a culinary             |\/\||//||||     |
|   /'-.._o     __.-'\    journey that will tantalize your taste bud and awaken your sense!      |||\\|/\\ ||     |
|   \      `````     /                                                                           | './\_/.' |     |
|   |``--........--'`|    Please Select Any of Them -                                            |          |     |
|    \              /                                                                            |          |     |
|     `'----------'`      1. New Order.                                                          |          |     |
|                         2. Bill Payment.                                                        '.______.'      |
|                         3. Exit.                                                                                |
\_____________________________________________________________________________________________ ___________________/
                                                                                              \\
                                                                                               \\    _(__)_        V
                                                                                                \\  '-e e -'__,--.__)
                                                                                                 \   (o_o)        )
                                                                                                       \. /___.  |
                                                                                                        ||| _)/_)/
                                                                                                        //_(/_(/_(
															   																							 
                           -> 1. I would like to make a new order please.
                           2. I would like to have the bill please.
                           3. I am ready to leave.
```

## 📜 Example Menu Order Output:
```												  
		                        ,---.           ,---.
		                       / /"`.\.--"""--./,'"\ \
		                       \ \    _       _    / /
		                        `./  / __   __ \  \,'
		                         /    /_O)_(_O\    \
		                         |  .-'  ___  `-.  |
		                     .--|       \_/       |--.
		                    ,'    \   \   |   /   /    `.
		                   /       `.  `--^--'  ,'       \
		                .-"""""-.    `--.___.--'     .-"""""-.
		.--------------/         \------------------/         \--------------.
		| .------------\         /----------------- \         /------------. |
		| |             `-`--`--'                    `--'--'-'             | |	
		| |   DISHES                                                (RM)   | |
		| |    --> 1. Burger                                         5.0   | |
		| |   2. Hotdog                                              4.0   | |
		| |   3. Pizza                                              15.0   | |
		| |                                                                | |
		| |   DRINKS                                                       | |
		| |   1. Strawbery Fanta                                     2.0   | |
		| |   2. Coca Cola                                           2.0   | |
		| |   3. A&W                                                 3.0   | |
		| |   4. Mineral Water                                       1.5   | |
		| |                                                                | |
		| |   DESSERTS                                                     | |
		| |   1. Canestrelli(Italian Egg York Cookies)              12.0   | |
		| |   2. Lemon Ricotta                                      17.5   | |
		| |   3. Chocolate Souffles                                  6.5   | |
		| |   4. Chocolate Puts De Creme                            14.0   | |
		| |________________________________________________________________| |
		|____________________________________________________________________|
		                      )__________|__|__________(
		                     |            ||            |
		                     |____________||____________|
		                      ),-----.(      ),-----.(
		                     ,'   ==.   \    /  .==    `.
		                    /            )  (            \
		                    `==========='    `==========='
```

## 📌 License
This project is open-source. Feel free to use and modify it as needed.
