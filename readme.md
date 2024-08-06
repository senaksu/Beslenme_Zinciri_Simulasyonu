# Canlı Türleri Arasındaki Beslenme İlişkilerinin Analizi: C Programlama Yaklaşımı

## Proje Özeti

 Doğal bir habitat içindeki farklı türler arasındaki etkileşimleri modellemeyi ve bu etkileşimlerin sonuçlarını analiz etmeyi amaçlamaktadır. Organizmalar arasındaki ilişkiler, beslenme zincirindeki etkileşimleri temsil eder ve bu ilişkilerin doğal yaşamdaki etkilerini anlamak için matematiksel bir model oluşturulmuştur.

**Beslenme Zinciri İlişkileri:**
- Bitki → Pire
- Böcek → Bitki
- Sinek → Pire
- Bitki → Sinek
- Sinek → Böcek
- Böcek → Pire

Bu proje C programlama dili kullanılarak geliştirilmiştir. Kalıtım ve soyut sınıf benzetimi kullanılarak yapılandırılmış ve modülerlik ile tek sorumluluk prensibi uygulanmıştır.

## Proje İçeriği

### Dosyalar

- **Canli.h / Canli.c**: Temel `CANLI` yapısını ve genel işlevleri tanımlar. Bu yapı, canlıları temsil eden genel özellikleri içerir: canlının değeri (`deger`), sembolü (`sembol`), görünümü (`gorunum`) ve yok edilmesi için bir fonksiyon (`yokEt`).

- **Bitki.h / Bitki.c**: Bitki türünü temsil eder. Bitki'nin özelliklerini ve davranışlarını içerir.

- **Bocek.h / Bocek.c**: Böcek türünü temsil eder. Böcek'nin özelliklerini ve davranışlarını içerir.

- **Sinek.h / Sinek.c**: Sinek türünü temsil eder. Sinek'in özelliklerini ve davranışlarını içerir.

- **Pire.h / Pire.c**: Pire türünü temsil eder. Pire'nin özelliklerini ve davranışlarını içerir.

- **Habitat.h / Habitat.c**: Habitat yapısını ve işlevlerini tanımlar. Habitat, içindeki canlıları barındırır ve etkileşimleri simüle eder.

- **main.c**: Programın ana fonksiyonunu içerir. Burada `textVeri.txt` dosyasından alınan verilerle matris oluşturulur ve simülasyon başlatılır.

### Ana Fonksiyonlar

- **goster()**: Habitat içindeki canlıları ekrana basar.

- **guncelle()**: Habitat içindeki canlıların etkileşimlerini simüle eder ve günceller.

- **yokEt()**: Bellek yönetimi için kullanılır, ayrılan bellek alanlarını serbest bırakır.

## Bellek Yönetimi

Bellek yönetimi dikkatlice yapılmıştır. Bellek sızıntılarına karşı önlemler alınmış ve programın performansı optimize edilmiştir. `yokEt` fonksiyonu, bellek sızıntılarını önlemek için ayrılan bellek alanlarını serbest bırakır.

## Sonuçlar

Simülasyon sonucunda, habitat içindeki canlı türleri arasında bir kazanan belirlenmiştir. Kazanan, simülasyonun başlangıcında belirlenen kurallar ve canlıların özellikleri temelinde belirlenmiştir. Program performansı optimize edilmiş ve bellek yönetimi konusunda gerekli önlemler alınmıştır.


**Sena AKSU**  

