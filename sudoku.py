import random
total=0
top=1
table=[]
def initiate():
    for i in range(0,9):
        table.insert(i,[])
        for j in range(0,9):
            table[i].insert(j,0)
    table[0][0]=6
def read(pathname):
    try:
        fl=open(pathname, 'r' )
    except IOError,e:
        print "file open error",e
    else:
        row=0
        col=0
        for line in fl:
            table.insert(row,[])
            for num in line[0:9]:
                if num==' ':
                    table[row].insert(col,0)
                else:
                    table[row].insert(col,int(num))
                col+=1
            row+=1
def lookup(rst,cst,num):
    #Requires: 0<rst,cst<3 1<=num<=9
    #Effects:/result==[(-1,-1)] <==> there is one number in Palace(rst,cst) equals to num
    #Effects:/result==[] <==> there is no suitable place for num in Palace(rst,cst)
    #Effects:len(/result)>=1 && /result!=[(-1,-1)] <==> there is one or more suitable place for num in Palace(rst,cst)
    cells=[]
    for i in range(0,3):
        for j in range(0,3):
            ron =rst*3+i
            con =cst*3+j
            if table[ron][con]==num:
                return [(-1,-1)]
            if table[ron][con]!=0:
                continue
            ps=True#Pass
            for t in range(0,9):
                if table[ron][t]==num or table[t][con]==num:
                    ps=False
                    break
            if ps:
                cells.insert(len(cells),(ron,con))
    return cells
def loop(subt,num):
    #Requires:10>=subt>=0  &&  9>=num>=1
    #Modifies:table,total
    #Effects:return <==> total==top || 
        global total
     #   print subt,num
        if total==top:
            return
        if num==10:
            total+=1
            if total==top:
                display()
            return 
        if subt==9:
          #  display()
            loop(0,num+1)
            return 
        rst=subt/3
        cst=subt%3
        cells=lookup(rst,cst,num)
        if subt==8 and num==3:
            display()
            print cells
        if len(cells)==0:
            return
        if cells[0]==(-1,-1):
            loop(subt+1,num)
        else:
             for cell in cells:
                #print "branches",len(cells)
                table[cell[0]][cell[1]]=num
                loop(subt+1,num)
                table[cell[0]][cell[1]]=0
def display():
    for i in range(0,9):
        for j in range(0,9):
            print str(table[i][j])+" ",
        print("")
read("easy.sdo")
display()
loop(0,1)

