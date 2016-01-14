package 
{
	
	import com.brightideas.sayaku.BrightIdeasWindowsNative;
	import flash.display.Sprite;
	import flash.events.KeyboardEvent;
	import flash.events.MouseEvent;
	import flash.ui.Keyboard;
	/**
	 * ...
	 * @author sayaku
	 */
	public class Sample extends Sprite 
	{
		private var ane:BrightIdeasWindowsNative;
		private var _x:int=0;
		private var _y:int=0;
		public function Sample():void 
		{
			ane = new BrightIdeasWindowsNative();  
			//偵聽鍵盤事件
			stage.addEventListener(KeyboardEvent.KEY_DOWN, keydown);
            
			
			//畫一個黑色矩形做為測試滑鼠點擊的區域
			var sp:Sprite = new Sprite();
			addChild(sp);
			sp.graphics.beginFill(0x000000);
			sp.graphics.drawRect(0, 0, 100, 100);
			sp.graphics.endFill();
			sp.buttonMode = true;
			sp.addEventListener(MouseEvent.CLICK, function(e:MouseEvent):void { trace("我點到了!!") } );
			sp.addEventListener(MouseEvent.MOUSE_DOWN, function(e:MouseEvent):void { trace("我按下了!!") } );
			sp.addEventListener(MouseEvent.MOUSE_UP, function(e:MouseEvent):void { trace("我放開了!!") } );
			
			
		}
		
		private function keydown(e:KeyboardEvent):void 
		{
			//根據鍵盤按的方向去移動滑鼠的位置
			switch(e.keyCode) {
				case Keyboard.UP:    _y-=5;
				                   ane.setMousePos(_x, _y);//設定原生游標位置
								   break;
				case Keyboard.DOWN:  _y+=5;
				                   ane.setMousePos(_x, _y);
								   break;
				case Keyboard.LEFT:  _x-=5;
				                   ane.setMousePos(_x, _y);
								   break;
				case Keyboard.RIGHT: _x+=5;
				                   ane.setMousePos(_x, _y);
								   break;
								   
				case Keyboard.SPACE:ane.keyDown(39);         //39是向右的方向鍵，所以按空白鍵等於按右鍵
								   break;
								   
				case Keyboard.ENTER:ane.mouseClick();        //指定ENTER按下去為滑鼠點擊
								   break;	
								   
				case Keyboard.A:ane.mouseDown();             //指定A按下去為滑鼠按下
								   break;
								   
				case Keyboard.B:ane.mouseUp();               //指定B按下去為滑鼠放開(一定要觸發mouseDown事件才會有mouseUp事件)
								   break;				   
				}
		}
		
	}
	
}