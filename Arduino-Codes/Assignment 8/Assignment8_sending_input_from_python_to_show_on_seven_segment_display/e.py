import serial  # Arduino er sathe serial connection
import time    # Time related kajer jonno

# Arduino er sathe connect hocche, amar setup onujayi
arduino = serial.Serial('COM7', 9600)
time.sleep(2)  # Arduino ke reset hobar jonno kichu somoy dilam

print("Welcome! Enter a digit (0-9) to show it on the Arduino display.")
print("Type 'quit' to exit the program.")

while True:
    user_input = input("Your digit (0-9): ")  # User theke input nicchi
    if user_input.lower() == 'quit':  # User quit likhle loop theke ber hoye jabe
        break
    if user_input.isdigit() and len(user_input) == 1:  # Jodi single digit hoy
        arduino.write(user_input.encode())  # Arduino te data pathacchi
        print(f"Sent '{user_input}' to Arduino.")
    else:
        print("Oops! Please enter a single digit (0-9) or 'quit'.")  # Input thik na hole message

arduino.close()  # Arduino connection bondho korchi
print("Exited ! Rerun the program to send more digits.")  # Program sesh hole message
