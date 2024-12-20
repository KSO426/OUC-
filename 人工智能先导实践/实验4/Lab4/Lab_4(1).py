import matplotlib.pyplot as plt
import numpy as np
import random

#
# 当 n=3 时，靠向红绿蓝顶点的沙子，分别用与顶点相同的颜色画。
#

# 创建一个图形对象，设置图形大小
fig, ax = plt.subplots(figsize=(6, 6))

# 设置坐标轴范围与刻度
ax.set_xlim([0, 600])
ax.set_ylim([0, 600])
ax.set_xticks(np.arange(0, 601, 100))
ax.set_yticks(np.arange(0, 601, 100))

# 绘制坐标轴
ax.axhline(0, color='black', linewidth=1)
ax.axvline(0, color='black', linewidth=1)

# 绘制圆心
circle_center = (300, 300)
ax.plot(circle_center[0], circle_center[1], marker='o', markersize=5, color='black')

# 绘制圆
circle = plt.Circle(circle_center, 300, fill=False, color='black', linewidth=1)
ax.add_patch(circle)

# 计算内接正三角形顶点坐标并绘制不同颜色的顶点
angle = 0
angle_increment = 2 * np.pi / 3  # 每个顶点间隔120度（2π/3弧度）
triangle_vertices_x = []
triangle_vertices_y = []
for i in range(3):
    x = circle_center[0] + 300 * np.cos(angle)
    y = circle_center[1] + 300 * np.sin(angle)
    triangle_vertices_x.append(x)
    triangle_vertices_y.append(y)
    # 三个顶点分别设置为红绿蓝
    if i == 0:
        color = 'red'
    elif i == 1:
        color = 'green'
    else:
        color = 'blue'
    ax.scatter(x, y, color=color, marker='o', s=300)
    angle += angle_increment

# 确定内接正三角形区域范围（简单通过判断点是否在三条边的同一侧来确定是否在三角形内）
def is_point_inside_triangle(x, y, vertices):
    def side(x1, y1, x2, y2, x3, y3):
        return (y2 - y1) * (x3 - x1) - (y3 - y1) * (x2 - x1)

    v1 = vertices[0]
    v2 = vertices[1]
    v3 = vertices[2]
    d1 = side(x, y, v1[0], v1[1], v2[0], v2[1])
    d2 = side(x, y, v2[0], v2[1], v3[0], v3[1])
    d3 = side(x, y, v3[0], v3[1], v1[0], v1[1])
    has_same_sign = (d1 >= 0 and d2 >= 0 and d3 >= 0) or (d1 <= 0 and d2 <= 0 and d3 <= 0)
    return has_same_sign

# 不断尝试随机生成坐标，直到生成的点在内接正三角形内
while 1:
    random_x = random.uniform(0, 600)
    random_y = random.uniform(0, 600)
    if is_point_inside_triangle(random_x, random_y, list(zip(triangle_vertices_x, triangle_vertices_y))):
        break

# 绘制刚刚生成的黄色的点，标记为start
ax.scatter(random_x, random_y, color='yellow', marker='o', s=5)
ax.text(random_x, random_y, f'start', fontsize=10)

# 下面重复10000次，模拟1万次放置沙粒
for i in range(10000):
    # 模拟掷骰子，1或4对应红色顶点连线中点，2或5对应绿色顶点连线中点，3或6对应蓝色顶点连线中点
    dice_result = random.randint(1, 6)
    # 确定这个新点的颜色
    if dice_result in [1, 4]:
        target_vertex_index = 0
        color = 'red'
    elif dice_result in [2, 5]:
        target_vertex_index = 1
        color = 'green'
    else:
        target_vertex_index = 2
        color = 'blue'

    # 计算连线中点坐标
    if i == 0: # 如果第一次循环，要用到start的黄点坐标
        mid_x = (random_x + triangle_vertices_x[target_vertex_index]) / 2
        mid_y = (random_y + triangle_vertices_y[target_vertex_index]) / 2
    else: # 如果不是第一次了，就用上次循环的结果的坐标
        mid_x = (mid_x + triangle_vertices_x[target_vertex_index]) / 2
        mid_y = (mid_y + triangle_vertices_y[target_vertex_index]) / 2

    # 绘制新的对应颜色的点
    ax.scatter(mid_x, mid_y, color=color, marker='o', s=10)

# 显示图形
plt.show()
