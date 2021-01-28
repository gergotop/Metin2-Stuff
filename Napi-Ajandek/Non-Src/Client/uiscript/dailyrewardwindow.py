import uiScriptLocale

window = {
	"name" : "DailyRewardDialog",
	"style" : ("movable", "float",),

	"x" : 0,
	"y" : 0,
						
	"width" : 200,
	"height" : 235,

	"children" :
	(
		{
			"name" : "Board",
			"type" : "board",
			"style" : ("attach",),

			"x" : 0,
			"y" : 0,

			"width" : 200,
			"height" : 200,

			"children" :
			(	
				{
					"name" : "board_bg","type" : "image","style" : ("attach",),"x" : 10,"y" : 30,"image" : "d:/ymir work/ui/public/dreward/reward_bg.tga"
				},			
				{
					"name" : "TitleBar",
					"type" : "titlebar",
					"style" : ("attach",),

					"x" : 6,
					"y" : 7,

					"width" : 188,
					"color" : "red",
					
					"children":
					(
						{ "name" : "TitleName", "type":"text", "x":0, "y":-1, "text":uiScriptLocale.DAILY_REWARD_TITLE, "all_align":"center" },
					),
				},	

				{
					"name" : "RewardSlot",
					"type" : "slot",
					
					"x" : 200/2-16,
					"y" : 90,
					
					"width" : 32,
					"height" : 96,
					
					"image" : "d:/ymir work/ui/public/Slot_Base.sub",
					
					"slot" : (
								{"index":0, "x":0, "y":0, "width":32, "height":96},
							),
				},
				{
					"name" : "GiftButton",
					"type" : "button",

					"x" :200/2-16-32,
					"y" : 90-32,

					"text" : "",

					"default_image" : "d:/ymir work/ui/public/dreward/reward.tga",
					"over_image" : "d:/ymir work/ui/public/dreward/reward_selected.tga",
					"down_image" : "d:/ymir work/ui/public/dreward/reward.tga",
				},				
			
			),
		},
	),
}