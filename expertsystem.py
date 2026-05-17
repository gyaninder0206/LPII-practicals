
# from tkinter import *

# # Main Window
# root = Tk()
# root.title("Help Desk Expert System")
# root.geometry("600x500")

# # Heading
# title = Label(root,
#               text="Help Desk Expert System",
#               font=("Arial", 16, "bold"))
# title.pack(pady=10)

# # Chat Area
# chat_area = Text(root,
#                  height=20,
#                  width=70)
# chat_area.pack(pady=10)

# # Input Box
# user_input = Entry(root,
#                    width=50,
#                    font=("Arial", 12))
# user_input.pack(pady=10)

# # Expert System Function
# def expert_system():

#     problem = user_input.get().lower()

#     chat_area.insert(END, "User : " + problem + "\n")

#     if problem == "password":
#         response = "Reset password using Forgot Password option."

#     elif problem == "internet":
#         response = "Restart router and check cables."

#     elif problem == "printer":
#         response = "Check printer connection and drivers."

#     elif problem == "virus":
#         response = "Run antivirus scan immediately."

#     elif problem == "slow system":
#         response = "Restart computer and remove temporary files."

#     elif problem == "bye":
#         response = "Thank you!"

#     else:
#         response = "Problem not found."

#     chat_area.insert(END, "Expert System : " + response + "\n\n")

#     user_input.delete(0, END)

# # Submit Button
# submit_button = Button(root,
#                        text="Submit",
#                        command=expert_system)

# submit_button.pack(pady=10)

# # Run Window
# root.mainloop()


# Expert System for Help Desk Management
# Using Forward Chaining Algorithm

# Knowledge Base
rules = {

    "wifi not working": "Restart router and reconnect WiFi",

    "forgot password": "Reset password using forgot password option",

    "computer slow": "Clear temporary files and restart system",

    "printer not working": "Check printer cable and install drivers",

    "internet issue": "Check network connection",

    "system hanging": "Close unnecessary programs and restart computer",

    "keyboard not working": "Reconnect keyboard or replace batteries",

    "mouse not working": "Check mouse connection",

    "screen blank": "Check monitor power cable",

    "software not opening": "Reinstall the software",

}

# Forward Chaining Algorithm
def expert_system(problem):

    for fact in rules:

        if problem == fact:
            return rules[fact]

    return "No solution found"

# Main Program
while True:

    problem = input("Enter problem: ").lower()

    solution = expert_system(problem)

    print("Solution:", solution)

    choice = input("Do you want to continue? (yes/no): ").lower()

    if choice == "no":
        print("Thank You")
        break