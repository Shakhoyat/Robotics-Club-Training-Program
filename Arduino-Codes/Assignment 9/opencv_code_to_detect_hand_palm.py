import cv2
import mediapipe as mp

# Camera open korchi
cam = cv2.VideoCapture(0)

# Mediapipe hands module initialize korchi
mp_hands = mp.solutions.hands
hands = mp_hands.Hands(max_num_hands=2)  # Ekbar e duita haath detect korte parbe
mp_draw = mp.solutions.drawing_utils  # Landmarks draw korar jonno

while True:
    ret, frame = cam.read()  # Camera theke frame read korchi
    if not ret:
        print("Frame read korte problem hocche!")
        break

    frame = cv2.flip(frame, 1)  # Mirror image avoid korar jonno frame flip korchi
    rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)  # BGR theke RGB te convert korchi as Mediapipe RGB use kore
    rgb.flags.writeable = False  # Performance improve korar jonno writeable flag false
    results = hands.process(rgb)  # Hand detection er jonno frame process korchi

    if results.multi_hand_landmarks:  # Jodi kono haath detect hoy
        for hand_landmarks in results.multi_hand_landmarks:
            # Landmarks draw korchi, lines shoho
            mp_draw.draw_landmarks(frame, hand_landmarks, mp_hands.HAND_CONNECTIONS)
            # Individual landmark position print korchi (optional)
            for id, lm in enumerate(hand_landmarks.landmark):
                h, w, _ = frame.shape
                x, y = int(lm.x * w), int(lm.y * h)
                cv2.circle(frame, (x, y), 5, (0, 255, 0), cv2.FILLED)
                # print(f"Landmark {id}: x={x}, y={y}")  # Debug info

    cv2.imshow("Hand Landmarks", frame)  # Frame ta display korchi

    if cv2.waitKey(1) & 0xFF == 27:  # ESC press korle loop theke ber hoye jabe
        break

# Resource release korchi
cam.release()
cv2.destroyAllWindows()