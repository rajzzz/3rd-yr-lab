import tensorflow as tf
from tensorflow.keras.applications import MobileNetV2
from tensorflow.keras.preprocessing import image
from tensorflow.keras.applications.mobilenet_v2 import preprocess_input, decode_predictions
import numpy as np

# Load pre-trained MobileNetV2 model + weights
model = MobileNetV2(weights='imagenet')

# Load an image to classify
img_path = 'dog.jpg'
img = image.load_img(img_path, target_size=(224, 224))
x = image.img_to_array(img)
x = np.expand_dims(x, axis=0)
x = preprocess_input(x)

# Predict
preds = model.predict(x)
# print('Predicted:', decode_predictions(preds, top=3)[0])
for pred in decode_predictions(preds, top=3)[0]:
    print(f"Predicted: {pred[1]} with confidence {pred[2]*100:.2f}%")

