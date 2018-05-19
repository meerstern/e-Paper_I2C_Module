# e-Paper_I2C_Module
The e-Paper I2C Module of Kicad Files for 1.54inch E-Ink raw display panel. 

e-Paper I2Cモジュールは[WAVESHARE製200x200, 1.54inch E-Inkディスプレイ][0]を搭載したモジュールです。
[WAVESHARE製200x200, 1.54inch E-Inkディスプレイ][0]はSPI接続ですが、
配線の容易性を実現するために[SPI I2CプロトコルブリッジIC SC18IS602B][1]を搭載してI2C化しています。
I2C接続のため、SPI接続に比べて描画速度が遅くなりますが、I2C接続で電源線と信号線2本で簡単に接続が可能です。
また、I2CはGroveコネクタを搭載することでラピッドプロトタイピングに対応しています。

サンプルプログラムはArduinoとSTM32(SW4STM32)のコードがあります。
[メーカ提供のデモプログラム][2]をSPI I2CプロトコルブリッジICを介して動作するように書き換えています。


<img src="https://github.com/meerstern/e-Paper_I2C_Module/blob/master/e-paper1.jpg" width="360">

<img src="https://github.com/meerstern/e-Paper_I2C_Module/blob/master/e-paper2.jpg" width="360">


## e-Paper I2Cモジュール仕様
  * WAVESHARE製200x200, 1.54inch E-Inkディスプレイ搭載
  * 電源3.3V、I2C接続(Groveコネクタ)
  * E-Inkディスプレイの制御ピンはSPI I2CプロトコルブリッジICのGPIOピンに接続されています
  　GPIO0:CS、GPIO1:Busy、GPIO2:DC、GPIO3:Reset
  * 取付穴M3、穴ピッチ44mm x29mm
  


[0]: https://www.waveshare.com/product/1.54inch-e-paper.htm "*0"
[1]: https://www.nxp.com/products/analog/signal-chain/bridges/ic-bus-to-spi-bridge:SC18IS602B "*1"
[2]: https://www.waveshare.com/wiki/1.54inch_e-Paper_Module "*2"
