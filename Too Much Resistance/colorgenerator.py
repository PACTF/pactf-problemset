dict = {0 : 'Black',1 : 'Brown',2 : 'Red',3 : 'Orange',4 : 'Yellow',5 : 'Green',6 : 'Blue',7 : 'Violet',8 : 'Grey',9 :'White'}

flag = input('Enter flag: ')

for chd in flag:
    ch = ord(chd)
    print(dict[(ch-ch%100)/100] + ' ' + dict[(ch%100-ch%10)/10] + ' ' + dict[ch%10])
