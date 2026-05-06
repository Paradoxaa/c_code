import tensorflow as tf
from tensorflow.keras.datasets import mnist
from tensorflow.keras import layers, models

def fc_nn():
    # 1. 加载数据
    (x_train, y_train), (x_test, y_test) = mnist.load_data()

    # 2. 数据预处理
    x_train = x_train.reshape(-1, 784) / 255.0
    x_test = x_test.reshape(-1, 784) / 255.0

    # one-hot编码
    y_train = tf.keras.utils.to_categorical(y_train, 10)
    y_test = tf.keras.utils.to_categorical(y_test, 10)

    # 3. 构建模型
    model = models.Sequential([
        layers.Input(shape=(784,)),
        layers.Dense(64, activation='relu'),
        layers.Dense(10, activation='softmax')
    ])

    # 4. 编译模型
    model.compile(
    optimizer='adam',
    loss='categorical_crossentropy',
    metrics=[
        'accuracy',
        tf.keras.metrics.Precision(),
        tf.keras.metrics.Recall()
    ])

    # 5. 训练
    model.fit(x_train, y_train, epochs=5, batch_size=32, validation_data=(x_test, y_test))

    # 6. 测试
    results = model.evaluate(x_test, y_test, return_dict=True)
    print("测试结果：")
    for key, value in results.items():
      print(key, ":", value)


if __name__ == '__main__':
    fc_nn()