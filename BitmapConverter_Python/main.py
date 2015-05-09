__author__ = 'Drona@elementz'


import sys
from PyQt4.QtGui import *
from PyQt4 import QtCore, QtGui
from image2LCDgui import Ui_Form
from tool import *

class MyForm(QtGui.QMainWindow):

    def __init__(self, parent=None):
        QtGui.QWidget.__init__(self, parent)
        self.ui = Ui_Form()
        self.ui.setupUi(self)
        self.fileDialog = QtGui.QFileDialog(self)

        self.ui.pushButton.clicked.connect(self.helloworld)

    def helloworld(self):
        filepath = str(QFileDialog.getOpenFileName())
        print "Generating hex file for " , filepath
        # pixmap = QPixmap(filepath)
        # self.ui.label.setPixmap(pixmap)
        imgtool(filepath)
        pixmap = QPixmap("Greyscale.jpg")
        self.ui.label.setPixmap(pixmap)

if __name__ == "__main__" :
    app = QtGui.QApplication(sys.argv)
    myapp = MyForm()
    myapp.show()
    sys.exit(app.exec_())