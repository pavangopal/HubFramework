#import "HUBComponent.h"

@protocol HUBComponentActionPerformer;
@class HUBIdentifier;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Delegate protocol used to perform Hub Framework actions from a component
 *
 *  You don't implement this protocol yourself. Instead, you @synthesize your component's `actionDelegate` property,
 *  and may choose to use this API to perform actions from your component implementation.
 */
@protocol HUBComponentActionDelegate <NSObject>

/**
 *  Perform an action with a given identifier from a component
 *
 *  @param component The component that wants the action to be performed
 *  @param identifier The identifier of the action to perform
 *
 *  @return A boolean indicating whether the action was successfully performed. For example, `NO` will be returned
 *          if no actions could be found for the given identifier, or if that action in turn returned `NO` as its
 *          outcome when being performed.
 */
- (BOOL)component:(id<HUBComponentActionPerformer>)component performActionWithIdentifier:(HUBIdentifier *)identifier;

@end

/**
 *  Extended Hub component protocol that adds the ability to perform actions
 *
 *  Use this protocol if you want your component to be able to perform actions based on custom user interactions
 *  or other events. By default The Hub Framework performs any actions associated with a component model's target
 *  when the component is selected by the user, but this protocol makes it possible to perform any other action
 *  whenever the component wants. For example, you might want to trigger an action whenever the user swipes the
 *  component, or something similar.
 *
 *  See `HUBComponent` and `HUBAction` for more information.
 */
@protocol HUBComponentActionPerformer <HUBComponent>

/**
 *  The object that acts as a delegate for performing actions on behalf of the component
 *
 *  Don't assign any custom objects to this property. Instead, just @sythensize it, so that the Hub Framework can
 *  assign an internal object to this property, to enable you to perform actions from the component.
 */
@property (nonatomic, weak, nullable) id<HUBComponentActionDelegate> actionDelegate;

@end

NS_ASSUME_NONNULL_END
