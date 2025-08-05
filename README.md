## 🎮 TRIVERSİ

Bu oyun, **Reversi** oyununun 3 kişilik versiyonudur. Kurallar klasik Reversi'den farklılık göstermektedir.

### 🧠 Oyun Hakkında

- Oyuna ilk olarak **kırmızı oyuncu (K)** başlar.
- İlk taş tahtanın ortasına yerleştirilmelidir.
- Diğer oyuncular sırasıyla **sarı (S)** ve **mavi (M)** taşlarla devam eder.
- Sıralama: K → S → M → K → ...

### 📋 Kurallar

1. Oyuncular yalnızca **mevcut taşların yanına** taş koyabilir.
2. Taşlar **dolu hücrelere** yerleştirilemez.
3. Rakip taşlar **çevrelendiğinde** ele geçirilip oynayan oyuncunun rengine döner.
4. Oyun **tahta tamamen dolduğunda** sona erer.
5. En çok taşa sahip olan oyuncu oyunu kazanır.
6. Eşitlik durumunda oyun **berabere** biter.

### 🛠 Derleme ve Çalıştırma

```bash
gcc triversi.c -o triversi
./triversi
```

> `triversi.c` dosyasını kendi dosya adınıza göre değiştirin.

### 🧾 Örnek Oyun Ekranı

```
Tahtanın boyutunu giriniz:
6

# # # # # #
# # # # # #
# # # # # #
# # # # # #
# # # # # #
# # # # # #

K'yi oynamak istedigin yeri (x,y) formatinda gir: 2,2
...
```

### 👨‍💻 Oyuncular

- **1. Oyuncu:** Kırmızı (K)
- **2. Oyuncu:** Sarı (S)
- **3. Oyuncu:** Mavi (M)

İYİ OYUNLAR 🎉
