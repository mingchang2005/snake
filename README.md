# 題目:貪食蛇  
班級:四資一乙  
姓名:張立名  
學號:41243226   
# 介紹--貪食蛇小遊戲    
⦾規則:  
●控制蛇的上下左右移動  
●碰壁或與自身碰撞則死亡  
●擁有三條性命，任意回合達到最大長度則可獲得滿分(最大長度X總生命數)  
●按下Z暫停，按下X結束  
#  功能條列說明  
1.設定最大長度(讓使用者數據化的自定義遊戲難度)  
2.讓使用者以WASD控制蛇的移動，Z、X則控制暫停及結束  
3.擁有記分板功能，生命耗盡或是達到最大分數則顯示結算畫面  
4.在結算後可以選擇結束或開啟新遊戲  
#  流程圖
https://github.com/mingchang2005/snake/blob/master/%E6%B5%81%E7%A8%8B%E5%9C%96.pdf  
#  技術使用說明
⦾規劃  
1.流程圖ch1   
2.標頭檔設置ch7  
3.中斷點監看ch2  
4.結構與自訂資料型別ch9  
⦾遊戲本體  
1.輸入/輸出ch3  
2.迴圈ch4,6  
3.隨機生成食物ch5  
4.多函式的應用ch7  
⦾修改/讀取檔案(最高分紀錄)  
1.檔案處理ch10  
#  !!專案使用方式!!  
1.下載rar檔案(01,02,03下載於相同目錄)  
[https://github.com/mingchang2005/snake/blob/master/snake.part01.rar](https://github.com/mingchang2005/snake/raw/master/snake.part01.rar)  
[https://github.com/mingchang2005/snake/raw/master/snake.part02.rar](https://github.com/mingchang2005/snake/raw/master/snake.part01.rar)  
[https://github.com/mingchang2005/snake/raw/master/snake.part03.rar](https://github.com/mingchang2005/snake/raw/master/snake.part03.rar)  
2.利用winrar解壓縮(解壓縮01即可)  
3.開啟資料夾中snake.sln，在VS2019中執行  
(如果直接執行.exe會因為與.txt所在目錄不同造成檔案讀取失敗)  
