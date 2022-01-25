# Proposal: DUCK-LIKE OBJECT HUNTER

## Synopsis

### Elements

My game will have three primary elements:

 - A randomly generated flock of targets that traverse the screen horizontally.
	- The targets will have different characteristics such as point value (smaller targets = more points) and speed
	- They will be different sizes and colors to differentiate them

 - A set of crosshairs that follows the mouse movement of the user

 - A textbox in the bottom-center portion of the screen to display the user's score

 - A textbox in the bottom-right that displays number of missed targets in a round

 - A textbox in the bottom-left that displays the time left

### Goal

The player's goal is to click on the targets as quickly as possible in order to 1) gain the maximum number of point & 2) not missing any valid targets that pass

### Game Play

The game begins with a score of 0 for the user and the crosshairs of the virtual rifle in the center of the screen. Upon pressing the space bar, the game is made active and the randomly generated targets begin moving across the screen. The birds will fly across the screen until you hit the 1 minute mark or until you miss 5 birds that have flow across the screen. At this point the game will freeze and a click of the space bar will restart the game with a score of 0. 

### Optional Elements

 - Increasing speed of bird as the time passes
 - Different point values for targets
	 - Target with negative point value (may (not) bring score to 0)
 - Start Graphic/End Graphic
 - Incorporation of sub-classes to represent different target types


## Functional requirements

 1. Crosshairs track the movement of the mouse

 2. Targets fly from one side of screen to opposite side of screen

 3. Each time a target is selected by the mouse the score changes

 4. Different targets have set, specific point values (smaller target = higher point value)

 5. Upon restart with the space bar, the crosshairs are centered and the score is zero'd

 6. The targets are released at a random height and side of screen

 7. Display in bottom-right starts at 0 at start of round and increments upon missed target

 8. Display in bottom-left starts at 60 seconds and counts down until 0 when the game ends

 9. When the target is selected it disappears

 10. The number of targets is fixed for a given round by a number of targets that is included in a target vector

 12. The missed target value will only increment upon the far side of the target colliding with the side which is when the target will disappear

 13. Point deduction for missing

 14. As time increases, the point value for a given target decreases in order to incentivize quick selection of the target

 15. Display in the bottom-center displays the score

 16. Pressing 'q' quits the game

## Open questions

 - How do we draw these targets? Shapes, only color, images?
 - How do we display text on screen to represent a score?
 - Is it possible to incorporate a start/end screen? How?
 - What is the best way to determine a variety of characteristics of the targets?
	- Point Value: Intrinsic Value of Sub-Class of Target?
	- Speed: Same as above?
	- Color: Is this done in the sprites step in UI.cxx?
	- Live: Boolean?
	- Traveling Right or Left: Done in subclass/main class/somewhere else?
	- Position: 
