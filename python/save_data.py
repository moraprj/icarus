import serial
import datetime
import zipfile
import os

def serial_data(port, file):
    ser = serial.Serial(port, 115200)
    ser.flush()
    f = open(file,'w')
    for i in range(100):
        texto = datetime.datetime.now().isoformat() + ',' + ser.readline()
        f.write(texto)
        print texto
    f.close()
    ser.close()


def gen_files(port):
    file = 'datos/' + datetime.datetime.now().isoformat() + '.txt'
    serial_data(port, file)
    return file

def compress_file(port, zip_name):
    zip = zipfile.ZipFile(zip_name, 'a')
    for i in range(10):
        file = gen_files(port)
        zip.write(file)
        os.remove(file)
    zip.close()                

def create_zip(port):
    while True:
        zip_name = 'datos/compress/' + datetime.datetime.now().isoformat() + '.zip'
        compress_file(port, zip_name)

create_zip('/dev/cu.usbmodem621')
    
