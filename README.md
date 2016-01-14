# WindowsMouseKeyboardANE
Windows OS Native Mouse&amp; Keyboard Event for Adobe AIR actionscript 3.0 ANE

Sample as3 code

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
		
			stage.addEventListener(KeyboardEvent.KEY_DOWN, keydown);
            
			
		//interactive area
			var sp:Sprite = new Sprite();
			addChild(sp);
			sp.graphics.beginFill(0x000000);
			sp.graphics.drawRect(0, 0, 100, 100);
			sp.graphics.endFill();
			sp.buttonMode = true;
			sp.addEventListener(MouseEvent.CLICK, function(e:MouseEvent):void { trace("mouseClick!!") } );
			sp.addEventListener(MouseEvent.MOUSE_DOWN, function(e:MouseEvent):void { trace("mouseDown!!") } );
			sp.addEventListener(MouseEvent.MOUSE_UP, function(e:MouseEvent):void { trace("mouseUp!!") } );
			
			
		}
		
		private function keydown(e:KeyboardEvent):void 
		{
			
			switch(e.keyCode) {
				case Keyboard.UP:    _y-=5;
				                   ane.setMousePos(_x, _y);//Native mouse position
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
								   
				case Keyboard.SPACE:ane.keyDown(39);         //39 is right arrow
								   break;
								   
				case Keyboard.ENTER:ane.mouseClick();        //ENTER
								   break;	
								   
				case Keyboard.A:ane.mouseDown();             //A
								   break;
								   
				case Keyboard.B:ane.mouseUp();               //B
								   break;				   
				}
		}
		
	}
	
}
