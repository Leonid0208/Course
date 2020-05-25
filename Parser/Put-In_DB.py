import sqlite3
import csv


def add_data(data):
    connect = sqlite3.connect('/home/leonid/Документы/Курсовая/Django/db.sqlite3')
    cur = connect.cursor()
    cur.execute("delete from JFS_offer where id>0")
    for i in range(1, 61):
        cur.execute('INSERT INTO JFS_offer VALUES(?, ?, ?, ?, ?, ?, ?)', [i]+data[i-1])
    connect.commit()
    cur.close()
    connect.close()


def open_file():
    with open('/home/leonid/Документы/Курсовая/Parser/file.txt', 'r') as f:
        file = csv.reader(f, delimiter='!')
        return list(file)


if __name__ == "__main__":
    add_data(open_file())
    print("DB was updated!")
