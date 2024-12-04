import sign_module

# Создание базы дорожных знаков
db = sign_module.SignDatabase()

# Добавление знаков
coords1 = sign_module.Coordinates()
coords1.longitude = 12.34
coords1.latitude = 56.78

sign1 = sign_module.Sign("Stop", 1, coords1)
db.add_sign(sign1)

# Поиск знака
found_sign = db.find_sign(1)
print(f"Found sign: {found_sign.name} at ({found_sign.coordinates.longitude}, {found_sign.coordinates.latitude})")

# Удаление знака
db.remove_sign(1)

# Попытка найти несуществующий знак
try:
    db.find_sign(1)
except Exception as e:
    print(e)
