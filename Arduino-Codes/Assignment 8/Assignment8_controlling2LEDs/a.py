import serial  # Serial library import korlam

# Serial connection initialize korlam
ser = serial.Serial('COM7', 9600)

while True:  
    print("\nLED Control Options:")  # LED control option gula dekhaitechi
    print("1 - Turn LED 1 ON (send 'A')")  # LED 1 on korar option
    print("2 - Turn LED 1 OFF (send 'a')")  # LED 1 off korar option
    print("3 - Turn LED 2 ON (send 'B')")  # LED 2 on korar option
    print("4 - Turn LED 2 OFF (send 'b')")  # LED 2 off korar option
    print("q - Quit program")  # Program bondho korar option
    
    choice = input("Enter your choice (1-4 or q): ")  # User theke input nilam
    
    if choice == '1':
        ser.write(b'A')  # LED 1 ON korar jonno signal pathailam
    elif choice == '2':
        ser.write(b'a')  # LED 1 OFF korar jonno signal pathailam
    elif choice == '3':
        ser.write(b'B')  # LED 2 ON korar jonno signal pathailam
    elif choice == '4':
        ser.write(b'b')  # LED 2 OFF korar jonno signal pathailam
    elif choice.lower() == 'q':
        break  # Loop theke ber hoye jabo
    else:
        print("Invalid choice!")  # Bhul input dile message dekhaibo

ser.close()  # Serial connection bondho korlam
print("Program ended. Serial connection closed.")  # Program sesh hoise message dekhaibo