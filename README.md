# e-Paper I2C モジュール
The e-Paper I2C Module of Kicad Files for 1.54inch E-Ink raw display panel. 

e-Paper I2Cモジュールは[WAVESHARE製200x200, 1.54inch E-Inkディスプレイ][0]を搭載したモジュールです。<br>
[WAVESHARE製200x200, 1.54inch E-Inkディスプレイ][0]はSPI接続ですが、
配線の容易性を実現するために[SPI I2CプロトコルブリッジIC SC18IS602B][1]を搭載してI2C化しています。<br>
I2C接続のため、SPI接続に比べて描画速度が遅くなりますが、I2C接続で電源線と信号線2本で簡単に接続が可能です。<br>
また、I2CはGroveコネクタを搭載することでラピッドプロトタイピングに対応しています。<br><br>

サンプルプログラムはArduinoとSTM32(SW4STM32)のコードがあります。<br>
[メーカ提供のデモプログラム][2]をSPI I2CプロトコルブリッジICを介して動作するように書き換えています。<br><br>

※注意※<br>
 基板裏面に[V2]マークがある場合は[V2版1.54inch E-Inkディスプレイ][2]のため、V2が付いたサンプルプログラムを使用してください。
V1とV2はハードウェア上の互換性がありますが、プログラム/ファームウェアの互換性はありません。2020年4月以降はV2版が出荷されます。<br>


<img src="https://github.com/meerstern/e-Paper_I2C_Module/blob/master/e-paper1.jpg" width="360">

<img src="https://github.com/meerstern/e-Paper_I2C_Module/blob/master/e-paper2.jpg" width="360">


<img src="https://github.com/meerstern/e-Paper_I2C_Module/blob/master/e-paper3.JPG" width="360">

<img src="https://github.com/meerstern/e-Paper_I2C_Module/blob/master/e-paper4.JPG" width="360">

## e-Paper I2Cモジュール仕様
  * WAVESHARE製200x200, 1.54inch E-Inkディスプレイ搭載
  * 電源3.3V、I2C接続(Groveコネクタ)
  * E-Inkディスプレイの制御ピンはSPI I2CプロトコルブリッジICのGPIOピンに接続されています<br>
  　GPIO0:CS、GPIO1:Busy、GPIO2:DC、GPIO3:Reset
  * 取付穴M3、穴ピッチ44mm x29mm
  


[0]: https://www.waveshare.com/product/1.54inch-e-paper.htm "*0"
[1]: https://www.nxp.com/products/analog/signal-chain/bridges/ic-bus-to-spi-bridge:SC18IS602B "*1"
[2]: https://www.waveshare.com/wiki/1.54inch_e-Paper_Module "*2"
