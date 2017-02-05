from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt



fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

x =[135,
115,
112,
109,
52,
74,
91,
95,
93,
55,
100,
60,
121,
100,
112,
80,
80,
105,
110,
122,
90,
120,
93,
121,
102,
85,
50,
80,
95,
87.5,
84,
93,
117,
125,
78,
107,
109]
y =[162,
145,
135,
136,
68,
100,
116,
108,
116,
72,
130,
80,
151,
130,
130,
110,
96,
135,
145,
150,
110,
150,
105,
137,
120,
125,
68,
100,
106,
105,
97,
114,
145,
141,
100,
132,
129
]
z =[0.8780487805,
0.9065934066,
0.8735632184,
0.8285714286,
0.7567567568,
0.8947368421,
0.8222222222,
0.8387096774,
0.8881987578,
0.9073170732,
0.8413793103,
0.9166666667,
0.8974358974,
0.85,
0.890052356,
0.8928571429,
0.9090909091,
0.915,
0.9340659341,
0.875,
0.8666666667,
0.8139534884,
0.9333333333,
0.8876404494,
0.9210526316,
0.8737864078,
0.9090909091,
0.9166666667,
0.8846153846,
0.8,
0.8214285714,
0.9210526316,
0.815920398,
0.8216216216,
0.9230769231,
0.9117647059,
0.900621118
]

ax.scatter(x, y, z, c='r', marker='o')

ax.set_xlabel('Snatch')
ax.set_ylabel('Clean & Jerk')
ax.set_zlabel('FS/BS')

plt.show()
