import serial  # Serial port use korbo

ser = serial.Serial('COM7', 9600)  # COM7 port e 9600 baud rate e connect

while True:
    print("\nEnter angle (0-180) or 'q' to quit")  # Angle ba quit option dekhao
    choice = input(">> ")  # User input nebo
    
    if choice.lower() == 'q':  # User quit korle loop bondho
        break
    try:
        angle = int(choice)  # Input ke integer e convert korbo
        if 0 <= angle <= 180:  # Angle valid kina check korbo
            ser.write(f"{angle}\n".encode())  # Angle serial e pathabo
        else:
            print("Angle must be 0-180!")  # Invalid angle hole message dekhao
    except ValueError:
        print("Enter a number!")  # Number na dile error dekhao

ser.close()  # Serial port bondho kore dao