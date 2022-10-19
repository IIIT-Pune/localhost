import time
import threading
from pynput.mouse import Button, Controller   #To control Mouse
from pynput.keyboard import Listener, KeyCode #To control Keyboard


delay = 0.001                       #Delay between Keys
button = Button.left                #Button to click
start_stop_key = KeyCode(char='s')  #Key to be pressed to start the auto clicker
exit_key = KeyCode(char='e')        #Key to be pressed to stop the auto clicker


class ClickMouse(threading.Thread):         #Class that extends threading
    def __init__(self, delay, button):      #To control mouse clicks
        super(ClickMouse, self).__init__()    
        self.delay = delay
        self.button = button
        self.running = False            #To check if the program is running or not
        self.program_running = True

    def start_clicking(self):       #To control threads externally
        self.running = True

    def stop_clicking(self):
        self.running = False

    def exit(self):
        self.stop_clicking()
        self.program_running = False

    def run(self):                      #To run when the thread starts
        while self.program_running:
            while self.running:
                mouse.click(self.button)
                time.sleep(self.delay)
            time.sleep(0.1)


mouse = Controller()
click_thread = ClickMouse(delay, button)
click_thread.start()


def on_press(key):                      #For the autoclicker to run/stop when start_stop_key is used
    if key == start_stop_key:           #and exit when the exit_key is pressed
        if click_thread.running:
            click_thread.stop_clicking()
        else:
            click_thread.start_clicking()
    elif key == exit_key:
        click_thread.exit()
        listener.stop()


with Listener(on_press=on_press) as listener:
    listener.join()
