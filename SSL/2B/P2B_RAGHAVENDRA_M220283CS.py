import pandas as pd
import numpy as np
import string
import math

file=open('doc1.txt')
f1=file.read()
file.close()
f1 =f1.translate(str.maketrans('', '', string.punctuation))
f1=(f1.lower()).split()

file=open('doc2.txt')
f2=file.read()
file.close()
f2 =f2.translate(str.maketrans('', '', string.punctuation))
f2=(f2.lower()).split()

file=open('doc3.txt')
f3=file.read()
file.close()
f3 =f3.translate(str.maketrans('', '', string.punctuation))
f3=(f3.lower()).split()

file=open('doc4.txt')
f4=file.read()
file.close()
f4 =f4.translate(str.maketrans('', '', string.punctuation))
f4=(f4.lower()).split()

token=set(f1+f2+f3+f4)


dict1,dict2,dict3,dict4={},{},{},{}
for i in token:
    dict1[i]=f1.count(i)
    dict2[i]=f2.count(i)
    dict3[i]=f3.count(i)
    dict4[i]=f4.count(i)

df = pd.DataFrame([dict1,dict2,dict3,dict4])



def magnitude(vector):
    return math.sqrt(sum(pow(element, 2) for element in vector))
def sim(vector1,vector2):
    m1=magnitude(vector1)
    m2=magnitude(vector2)
    dot=np.dot(vector1,vector2)
    sim=dot/(m1*m2)
    if(sim>=1):
        sim=1
        return sim
    else:    
        sim=round(sim,8)    
        return sim
def sim_matrixrix(df):
    sim_matrix=[]
    for index1,row1 in df.iterrows():
        sim_row=[]
        for index2,row2 in df.iterrows():
            sim_row.append(sim(row1,row2))
        sim_matrix.append(sim_row) 
    return sim_matrix  


sim_matrix=sim_matrixrix(df)

print(np.array(sim_matrix))    
   