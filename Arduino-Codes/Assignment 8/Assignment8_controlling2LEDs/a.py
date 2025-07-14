import serial

# Initialize serial connection
ser = serial.Serial('COM7', 9600)

while True:  
    print("\nLED Control Options:")
    print("1 - Turn LED 1 ON (send 'A')")
    print("2 - Turn LED 1 OFF (send 'a')")
    print("3 - Turn LED 2 ON (send 'B')")
    print("4 - Turn LED 2 OFF (send 'b')")
    print("q - Quit program")
    
    choice = input("Enter your choice (1-4 or q): ")
    
    if choice == '1':
        ser.write(b'A')  # LED 1 ON
    elif choice == '2':
        ser.write(b'a')  # LED 1 OFF
    elif choice == '3':
        ser.write(b'B')  # LED 2 ON
    elif choice == '4':
        ser.write(b'b')  # LED 2 OFF
    elif choice.lower() == 'q':
        break
    else:
        print("Invalid choice!")

ser.close()
print("Program ended. Serial connection closed.")