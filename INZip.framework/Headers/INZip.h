//
//  INZip.h
//  INZip
//
//  Created by 晨风 on 2017/4/17.
//  Copyright © 2017年 晨风. All rights reserved.
//

#import <Foundation/Foundation.h>

//! Project version number for INZip.
FOUNDATION_EXPORT double INZipVersionNumber;

//! Project version string for INZip.
FOUNDATION_EXPORT const unsigned char INZipVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <INZip/PublicHeader.h>


typedef NS_ENUM(NSUInteger, INZipCompressionMode) {
    INZipCompressionModeNo,
    INZipCompressionModeSpeed,
    INZipCompressionModeDefault,
    INZipCompressionModeBest,
};

typedef void(^INZipProgressBlock)(double progress);


@interface INZip : NSObject

#pragma mark - zip

/**
 压缩文件

 @param paths 文件路径
 @param zipFilePath 压缩文件路径
 @param mode 压缩模式
 @param password 密码
 @param progressBlcok 进度回调
 @param error 错误信息
 @return 成功/失败
 */
+ (BOOL)zipFiles:(NSArray<NSString *> * _Nonnull)paths zipFilePath:(NSString * _Nonnull)zipFilePath compressionMode:(INZipCompressionMode)mode password:(NSString * _Nullable)password  progress:(INZipProgressBlock _Nullable)progressBlcok error:(NSError *_Nullable * _Nullable)error;

/**
 mode: INZipCompressionModeBest
 password: nil
 */
+ (BOOL)zipFiles:(NSArray<NSString *> * _Nonnull)paths zipFilePath:(NSString * _Nonnull)zipFilePath error:(NSError *_Nullable * _Nullable)error;

+ (NSData * _Nullable)zipData:(NSData * _Nonnull)data filename:(NSString * _Nonnull)name progress:(INZipProgressBlock _Nullable)progressBlcok;

#pragma mark - unzip

/**
 解压缩

 @param zipFilePath 压缩包文件路径
 @param destination 目标路径
 @param overwrite 是否覆盖原文件
 @param password 密码
 @param progressBlock 进度
 @param error 错误信息
 @return 成功/失败
 */
+ (BOOL)unzipFile:(NSString * _Nonnull)zipFilePath destinationPath:(NSString * _Nonnull)destination overwrite:(BOOL)overwrite password:(NSString * _Nullable)password progress:(INZipProgressBlock _Nullable)progressBlock error:(NSError *_Nullable *_Nullable)error;

/**
 overwrite: YES
 password
 */
+ (BOOL)unzipFile:(NSString * _Nonnull)zipFilePath destinationPath:(NSString * _Nonnull)destination error:(NSError *_Nullable *_Nullable)error;

@end
