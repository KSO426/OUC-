import math

import matplotlib.pyplot as plt
import numpy as np
import random

# 创建一个600*600像素的画布
fig, ax = plt.subplots(figsize=(6, 6), dpi=100)

# 绘制直径为600像素，圆心在(300, 300)的圆
circle = plt.Circle((300, 300), 300, fill=False)
ax.add_patch(circle)

# 计算圆内接正五边形的顶点坐标
radius = 300
angle_step = 2 * np.pi / 5
vertices = np.array([
    [300 + radius * np.cos(i * angle_step), 300 + radius * np.sin(i * angle_step)]
    for i in range(5)
])

# 顶点颜色
colors = ['r', 'g', 'b', 'm', 'gray']

# 绘制内接正五边形的5个顶点，设置颜色和大小
for i in range(5):
    ax.scatter(vertices[i, 0], vertices[i, 1], c=colors[i], s=300)

# 在正五边形内部随机取一点（颜色设为黄色）
min_x, max_x = np.min(vertices[:, 0]), np.max(vertices[:, 0])
min_y, max_y = np.min(vertices[:, 1]), np.max(vertices[:, 1])
random_point = np.array([random.uniform(min_x, max_x),
                         random.uniform(min_y, max_y)])
ax.scatter(random_point[0], random_point[1], c='y', s=10)
ax.text(random_point[0], random_point[1], f'start', fontsize=10)

last_dice_result = None
point_count = 0
# 定义黄金分割比例，约为0.618
golden_ratio = (math.sqrt(5) - 1) / 2

while point_count < 10000:
    dice_result = random.randint(1, 5)
    if dice_result == last_dice_result:
        continue
    # 根据骰子结果计算新的点坐标(黄金分割点)
    #new_point = (random_point + vertices[dice_result - 1]) / 2
    new_point = vertices[dice_result - 1] + (random_point - vertices[dice_result - 1]) * golden_ratio
    #或者
    #new_point = random_point + (vertices[dice_result - 1] - random_point) * golden_ratio

    ax.scatter(new_point[0], new_point[1], c=colors[dice_result - 1], s=10)
    random_point = new_point
    last_dice_result = dice_result
    point_count += 1

# 显示图形
plt.show()