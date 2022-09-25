import pandas as pd
student = pd.read_csv('student_marks.csv')

student['math score'].fillna(student['math score'].mean())
student['reading score'].fillna(student['reading score'].mean())
student['writing score'].fillna(student['writing score'].mean())

"""problem-1"""

m=student['math score'].mean()
r=student['reading score'].mean()
s=student['writing score'].mean()

m_std=student['math score'].std()
r_std=student['reading score'].std()
w_std=student['writing score'].std()

mark_data={
          'math score ':[m,m_std],
          'reading score':[r,r_std],
          'writing score':[s,w_std]}

mark_df=pd.DataFrame(mark_data)
mark_df=mark_df.set_index([pd.Index(["mean","standard deviation"])])

print(mark_df)

"""problem-2"""

my_dict={}
for index,row in student.iterrows():
    my_dict['S'+str(index+1)+'_'+row.group[-1]]=[row[-3],row[-2],row[-1]]
    
flag=0;    
test=input("Enter Code: ")
for key,value in my_dict.items():
    if test==key:
        print(key,':',value)
        flag=1
if flag==0:
    print("wrong input!")

"""problem-3"""

def student_stat(student):
    table = {"Group":['A','B','C','D','E'],
            "Mean math score":[],
            "Standard deviation math score":[],
            "Prob_scoring above 50_maths":[]}
    
    p=student.groupby('group')['math score'].mean()
    table['Mean math score']=[p[0],p[1],p[2],p[3] ,p[4]]
    p=student.groupby('group')['math score'].std()
    table['Standard deviation math score']=[p[0],p[1],p[2],p[3] ,p[4]]
    count=student.groupby('group')['math score'].count()
    maxf=student[student['math score'] > 50].groupby('group')['math score'].count()
    table['Prob_scoring above 50_maths']=[maxf[0]/count[0],maxf[1]/count[1],maxf[2]/count[2],maxf[3]/count[3],maxf[4]/count[4]]
    
    
    print(pd.DataFrame(table))
    
student_stat(student)
    