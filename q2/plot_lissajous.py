#!/usr/bin/env python3
import numpy as np
import matplotlib.pyplot as plt
import os

def read_lissajous_data(filename):
    """读取Lissajous数据文件"""
    data = []
    try:
        with open(filename, 'r') as f:
            for line in f:
                line = line.strip()
                if line:  # 跳过空行
                    parts = line.split()
                    if len(parts) >= 3:
                        x = float(parts[0])
                        y = float(parts[1])
                        z = float(parts[2])
                        data.append([x, y, z])
    except FileNotFoundError:
        print(f"Error: File {filename} not found")
        return None
    except Exception as e:
        print(f"Error reading file: {e}")
        return None
    
    return np.array(data)

def plot_lissajous(data):
    """绘制Lissajous曲线"""
    if data is None or len(data) == 0:
        print("No data to plot")
        return
    
    x = data[:, 0]
    y = data[:, 1]  # sin(2x)
    z = data[:, 2]  # cos(3x)
    
    # 创建图形
    fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(15, 6))
    
    # 子图1: Lissajous曲线 (sin(2x) vs cos(3x))
    ax1.plot(y, z, 'b-', linewidth=1.5, alpha=0.8)
    ax1.scatter(y, z, c=x, cmap='viridis', s=10, alpha=0.6)
    ax1.set_xlabel('sin(2x)', fontsize=12)
    ax1.set_ylabel('cos(3x)', fontsize=12)
    ax1.set_title('Lissajous Curve: sin(2x) vs cos(3x)', fontsize=14)
    ax1.grid(True, alpha=0.3)
    ax1.set_aspect('equal')
    ax1.set_xlim(-1.1, 1.1)
    ax1.set_ylim(-1.1, 1.1)
    
    # 添加颜色条
    cbar = plt.colorbar(ax1.collections[0], ax=ax1)
    cbar.set_label('x value', fontsize=10)
    
    # 子图2: 参数化曲线 (x vs sin(2x) 和 x vs cos(3x))
    ax2.plot(x, y, 'r-', label='sin(2x)', linewidth=2)
    ax2.plot(x, z, 'g-', label='cos(3x)', linewidth=2)
    ax2.set_xlabel('x', fontsize=12)
    ax2.set_ylabel('Function values', fontsize=12)
    ax2.set_title('Parameterized Functions', fontsize=14)
    ax2.legend()
    ax2.grid(True, alpha=0.3)
    ax2.set_xlim(-5, 5)
    ax2.set_ylim(-1.1, 1.1)
    
    plt.tight_layout()
    
    # 保存图形
    plt.savefig('lissajous_plot.png', dpi=300, bbox_inches='tight')
    print("Plot saved as 'lissajous_plot.png'")
    
    # 显示图形（如果在交互环境中）
    try:
        plt.show()
    except:
        pass

def print_summary(data):
    """打印数据摘要"""
    if data is None or len(data) == 0:
        return
    
    x = data[:, 0]
    y = data[:, 1]
    z = data[:, 2]
    
    print(f"\n=== Lissajous Data Summary ===")
    print(f"Total points: {len(data)}")
    print(f"X range: [{x.min():.3f}, {x.max():.3f}]")
    print(f"Y (sin(2x)) range: [{y.min():.3f}, {y.max():.3f}]")
    print(f"Z (cos(3x)) range: [{z.min():.3f}, {z.max():.3f}]")
    print(f"X step size: {(x.max() - x.min()) / (len(x) - 1):.3f}")

def main():
    # 检查文件是否存在
    filename = "lissajous.txt"
    if not os.path.exists(filename):
        print(f"Error: {filename} not found in current directory")
        print("Please make sure the lissajous.txt file exists")
        return
    
    # 读取数据
    print(f"Reading data from {filename}...")
    data = read_lissajous_data(filename)
    
    if data is not None:
        print_summary(data)
        plot_lissajous(data)
    else:
        print("Failed to read data")

if __name__ == "__main__":
    main()
