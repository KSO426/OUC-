import matplotlib.pyplot as plt
import numpy as np
import random

#
# 当 n=4 和 5 时，添加一个限制：如果掷出的点数又指向上一次被选中的贝壳（顶点），则重新掷。
#

# 创建一个600*600像素的画布
fig, ax = plt.subplots(figsize=(6, 6), dpi=100)

# 绘制直径为600像素，圆心在(300, 300)的圆
circle = plt.Circle((300, 300), 300, fill=False)
ax.add_patch(circle)

# 计算内接正方形的四个顶点坐标
half_side_length = 300 / np.sqrt(2)
vertices = np.array([
    [300 + half_side_length, 300 + half_side_length],  # 右上顶点
    [300 - half_side_length, 300 + half_side_length],  # 左上顶点
    [300 - half_side_length, 300 - half_side_length],  # 左下顶点
    [300 + half_side_length, 300 - half_side_length]  # 右下顶点
])
# 顶点颜色
colors = ['r', 'g', 'b', 'm']
# 绘制内接正方形的四个顶点，设置颜色和大小
for i in range(4):
    ax.scatter(vertices[i, 0], vertices[i, 1], c=colors[i], s=300)

# 在正方形内部随机取一点（颜色设为黄色）
random_point = np.array([random.uniform(300 - half_side_length, 300 + half_side_length),
                         random.uniform(300 - half_side_length, 300 + half_side_length)])
ax.scatter(random_point[0], random_point[1], c='y', s=10)
ax.text(random_point[0], random_point[1], f'start', fontsize=10)

last_dice_result = None
point_count = 0
while point_count < 10000:
    dice_result = random.randint(1, 4)
    if dice_result == last_dice_result:
        continue

    # 根据骰子结果计算新的点坐标
    new_point = (random_point + vertices[dice_result - 1]) / 2
    ax.scatter(new_point[0], new_point[1], c=colors[dice_result - 1], s=10)
    random_point = new_point
    last_dice_result = dice_result
    point_count += 1

# 显示图形
plt.show()