//
//  BDAssetsSource.h
//
//  Objects that conform to |BDAssetsSource| know how to fill in an array
//  of objects that conform to |BDSelectableAsset|.
//
//  Created by Brian Dewey on 5/19/11.
//  Copyright 2011 Brian Dewey.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//

#import <Foundation/Foundation.h>

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

@protocol BDSelectableAssetDelegate;
@protocol BDAssetsSource <NSObject>

//
//  The title of this asset source.
//

@property (nonatomic, readonly) NSString *title;

//
//  Return immediately. In the background, fill in |assets| with the appropriate
//  objects that conform to |BDSelectableAsset|. Each object should have its
//  delegate property set to |delegate|.
//
//  Optionally fill |children| with additional |BDAssetsSource| objects that
//  represent child sources.
//
//  When done, call |completion|.
//

- (void)asyncFillArrayWithChildren:(NSMutableArray *)children
                         andAssets:(NSMutableArray *)assets 
       withSelectableAssetDelegate:(id<BDSelectableAssetDelegate>)delegate
                        completion:(void (^)())completion;

@optional

//
//  Optional method to get a visual thumbnail for this asset source.
//

- (void)asyncThumbnail:(void(^)(UIImage *thumbnail))completion;

@end
