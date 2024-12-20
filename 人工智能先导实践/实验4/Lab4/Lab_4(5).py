import matplotlib.pyplot as plt
import numpy as np
import random

# 获取用户输入部分
n = int(input("请输入正多边形的顶点数n: "))
reroll_conditions = input("请输入重掷条件（可多选，以空格分隔，选项为：1.无限制 2.不与上次点数相同 3.不与上次点数差的绝对值为2）: ").split()
coordinate_option = input("请输入坐标选项（单选：1.中点 2.黄金分割点）: ")

# 图形绘制初始化部分
fig, ax = plt.subplots(figsize=(6, 6), dpi=100)
circle = plt.Circle((300, 300), 300, fill=False)
ax.add_patch(circle)

# 内接正n边形顶点相关操作部分
radius = 300
angle_step = 2 * np.pi / n
vertices = np.array([
    [300 + radius * np.cos(i * angle_step), 300 + radius * np.sin(i * angle_step)]
    for i in range(n)
])
color_list = ["r", "g", "b", "m", "gray"] * (n // 5 + 1)
color_list = color_list[:n]
for i in range(n):
    ax.scatter(vertices[i, 0], vertices[i, 1], c=color_list[i], s=300)

# 正n边形内部随机点生成部分
min_x, max_x = np.min(vertices[:, 0]), np.max(vertices[:, 0])
min_y, max_y = np.min(vertices[:, 1]), np.max(vertices[:, 1])
random_point = np.array([random.uniform(min_x, max_x),
                         random.uniform(min_y, max_y)])
ax.scatter(random_point[0], random_point[1], c='y', s=10)

# 模拟掷骰子放置新点循环操作部分
last_dice_result = None
point_count = 0
while point_count < 10000:
    dice_result = random.randint(1, n)
    if ("2" in reroll_conditions and dice_result == last_dice_result) or \
            ("3" in reroll_conditions and point_count>0 and abs(dice_result - last_dice_result) == 2):
        continue
    if coordinate_option == "1":
        new_point = (random_point + vertices[dice_result - 1]) / 2
    elif coordinate_option == "2":
        golden_ratio = (np.sqrt(5) - 1) / 2
        new_point = random_point + (vertices[dice_result - 1] - random_point) * golden_ratio
    else:
        print("输入的坐标选项不正确，请重新运行程序输入正确选项")
        break
    ax.scatter(new_point[0], new_point[1], c=color_list[dice_result - 1], s=10)
    random_point = new_point
    last_dice_result = dice_result
    point_count += 1

# 图形显示设置部分
ax.set_xlim(0, 600)
ax.set_ylim(0, 600)
ax.set_aspect('equal')
plt.show()