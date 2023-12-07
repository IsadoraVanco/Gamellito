'''
Exemplo de media player simples

Não esqueça de baixar o Python no sistema. 
Para linux:
sudo apt install python3
sudo apt install python3-pip 

Verificar se o tkinter está presente:
python3 -m tkinter
Se não:
sudo apt-get install python3-tk

É necessário baixar as bibliotecas para utilizar:
(opencv instala numpy também)
pip install opencv-python pillow

'''
import tkinter as tk
from tkinter import filedialog
from tkinter import messagebox
import cv2
from PIL import Image, ImageTk

class VideoPlayer:
    def __init__(self, root):
        self.root = root
        self.root.title("Reprodutor de Vídeo Simples")

        self.video_frame = tk.Label(root)
        self.video_frame.pack()

        self.btn_open = tk.Button(root, text="Abrir Vídeo", command=self.open_video)
        self.btn_open.pack(pady=10)

        self.btn_play = tk.Button(root, text="Reproduzir", command=self.play_video)
        self.btn_play.pack(pady=5)

        self.btn_stop = tk.Button(root, text="Parar", command=self.stop_video)
        self.btn_stop.pack(pady=5)

        self.video_path = ""

    def open_video(self):
        self.video_path = filedialog.askopenfilename(filetypes=[("Arquivos de Vídeo", "*.mp4;*.avi;*.mkv")])

    def play_video(self):
        if not self.video_path:
            messagebox.showinfo("Aviso", "Selecione um vídeo primeiro.")
            return

        cap = cv2.VideoCapture(self.video_path)

        while True:
            ret, frame = cap.read()
            if not ret:
                break

            frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
            img = ImageTk.PhotoImage(Image.fromarray(frame))

            self.video_frame.img = img
            self.video_frame.config(image=img)
            self.root.update_idletasks()
            self.root.update()

        cap.release()

    def stop_video(self):
        messagebox.showinfo("Aviso", "Vídeo parado.")

if __name__ == "__main__":
    root = tk.Tk()
    player = VideoPlayer(root)
    root.mainloop()
