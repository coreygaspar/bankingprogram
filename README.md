# Airgead Banking Program


**Summarize the project and what problem it was solving.**
---
The Airgead Banking Program is a tool used to calculate investment growth over a set number of years, both with and without monthly deposits. The purpose of this program is to show the user the importance of compound interest and monthly contributions. Most people, especially younger people, don't understand the concept of compound interest and struggle to understand the importance of saving money over time. This program gives people a visualization on how important it is to save money.


**What did you do particularly well?**
---
I think that I did particularly well with the calculations. I implemented compound interest formulas and used monthly compound interest, which produces a more accurate calculation of total savings. I also think I did particularly well with the output formatting. I ran into a few issues with the calculations being off due to formatting but I was able to fix them. For example, my calculations had too many zeros at the end at one point so I had to make sure it was rounded off to two decimal places.


**Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?**
---
For starters, I should have created a limit for interest rate. I should have set a limit for the interest rate to be no greater than 100% but it can exceed that. I could even make that number even smaller if I was trying to be realistic. My code also allows users to enter high deposit values, which could cause some overflow issues. 


**Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?**
---
The most challenging part of this project, to me, was formatting the output tables. I was running into alignment issues with the calculated values and there were big spaces between the dollar signs and the actual values. To fix this issue from occuring everytime I right-aligned my values, I used setw() and ostringstream. I also struggled with understanding how monthly interest is applied. To overcome this, I broke down each formula into smaller pieces and tested with smaller values. I also decided that it would be best to add as many detailed comments to my code to avoid confusion.


**What skills from this project will be particularly transferable to other projects or course work?**
---
I believe that the use of Object-Oriented Programming will be transferable to other projects or coursework. For example, I used main.cpp for managing the user interactions while I had BankingApp.h and BankingApp.cpp handle all of the calculations. I also feel that the skill of writing maintainable code through the use of descriptive comments will also be transferable. I wrote as many descriptive comments as I could throughout the program so that in the future, if I decide to come back to this project and make improvements, I will know what code does what.

**How did you make this program maintainable, readable, and adaptable?**
---
As I have stated before, I wrote many descriptive comments throughout the program as a reference for me in the future in case I decide to fix things or make any updates. I also tried to use clear variable names for better readability. This will also be useful for me in the future because I will know what each variable is used for.
