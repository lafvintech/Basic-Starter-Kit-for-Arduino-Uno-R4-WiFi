Creating, Opening, and Saving Sketches
========================================

Panel of Arduino IDE
------------------------------

.. image:: img/Creat_Skerch0.png

1. **Verify**: Compile your code. Any syntax problem will be prompted with errors.

2. **Upload**: Upload the code to your board. When you click the button, the RX and TX LEDs on the board will flicker fast and won't stop until the upload is done.

3. **Debug**: For line-by-line error checking.

4. **Select Board**: Quick setup board and port.

5. **Serial Plotter**: Check the change of reading value.

6. **Serial Monitor**: Click the button and a window will appear. It receives the data sent from your control board. It is very useful for debugging.

7. **File**: Click the menu and a drop-down list will appear, including file creating, opening, saving, closing, some parameter configuring, etc.

8. **Edit**: Click the menu. On the drop-down list, there are some editing operations like **Cut**, **Copy**, **Paste**, **Find**, and so on, with their corresponding shortcuts.

9. **Sketch**: Includes operations like **Verify**, **Upload**, **Add** files, etc. A more important function is **Include Library** – where you can add libraries.

10. **Tool**: Includes some tools – the most frequently used Board (the board you use) and Port (the port your board is at). Every time you want to upload the code, you need to select or check them.

11. **Help**: If you're a beginner, you may check the options under the menu and get the help you need, including operations in IDE, introduction information, troubleshooting, code explanation, etc.

12. **Output Bar**: Switch the output tab here.

13. **Output Window**: Print information.

14. **Board and Port**: Here you can preview the board and port selected for code upload. You can select them again by **Tools** -> **Board** / **Port** if any is incorrect.

15. The editing area of the IDE. You can write code here.

16. **Sketchbook**: For managing sketch files.

17. **Board Manager**: For managing board driver.

18. **Library Manager**: For managing your library files.

19. **Debug**: Help debugging code.

20. **Search**: Search the codes from your sketches.



Creating, Saving Sketches
----------------------------------------

#. When you open the Arduino IDE for the first time or create a new sketch, you will see a page like this, where the Arduino IDE creates a new file for you, which is called a "sketch".

   .. image:: img/Creat_Skerch1.png

   These sketch files have a regular temporary name, from which you can tell the date the file was created. ``sketch_oct14a.ino`` means October 14th first sketch, ``.ino`` is the file format of this sketch.

#. Now let's try to create a new sketch. Copy the following code into the Arduino IDE to replace the original code.


   .. image:: img/Creat_Skerch2.png

   .. code-block:: Arduino

       void setup() {
           // put your setup code here, to run once:
           pinMode(13,OUTPUT); 
       }

       void loop() {
           // put your main code here, to run repeatedly:
           digitalWrite(13,HIGH);
           delay(500);
           digitalWrite(13,LOW);
           delay(500);
       }

#. Press ``Ctrl+S`` or click **File** -> **Save**. The Sketch is saved in: ``C:\Users\{your_user}\Documents\Arduino`` by default, you can rename it or find a new path to save it.

   .. image:: img/Creat_Skerch3.png

#. After successful saving, you will see that the name in the Arduino IDE has been updated.

   .. image:: img/Creat_Skerch4.png

Opening a Sketch
----------------

1. Click on ``File`` in the top menu bar.
2. Select ``Open`` from the dropdown menu.
3. Navigate to the folder where your sketch is saved (Arduino sketches typically have a ``.ino`` file extension).
4. Select the sketch file and click ``Open``.
You can also quickly open recently used sketches by going to ``File > Sketchbook`` and selecting a sketch from the list.
    .. image:: img/Creat_Skerch5.png

Please continue with the next section to learn how to upload this created sketch to your Arduino board.