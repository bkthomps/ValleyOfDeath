//===============================================
// DragonFireSDK.h
//===============================================
#include <stdio.h>

#pragma comment(lib,"C:/DragonFireSDK/DragonFireSDK.lib")

//===============================================
// App.cpp must provide these functions
void AppMain(); // app starts here
void OnTimer(); // 30 times per sec - update game here
void AppExit(); // app ends here - save game if desired

//===============================================


int WorldSetxy(int x,int y);

int ImageAdd(char *filename);
int ImageGetWidth(int im);
int ImageGetHeight(int im);

int ViewAdd(int im,int x,int y);
int ViewAdd(char *filename,int x,int y);
int ViewAdd(char *filename,int x,int y,int (*callback)(int id,int event,int x,int y),int id);

int ViewGetx(int vw);
int ViewGety(int vw);
int ViewGetWidth(int vw);
int ViewGetHeight(int vw);

int ViewSetxy(int vw,int x,int y);
int ViewSetImage(int vw,int im);
int ViewSetVisible(int vw,int flag);

int TouchAdd(int x,int y,int width,int height,int (*callback)(int id,int event,int x,int y),int id); // event: 1=down, 2=move, 3=up
int TouchGetxy(int tc,int &x,int &y);
int TouchSetxy(int tc,int x,int y);
int TouchSetVisible(int tc,int flag);

void RandomSetSeed(unsigned int seed);
void Randomize();
int Random(unsigned int range); // ret number from 0 to <range

int ButtonAdd(char *filename,int x,int y,int (*callback)(int id),int id);
int ButtonSetVisible(int bt,int flag);

int PushButtonAdd(char *filename,int x,int y,int (*callback)(int id),int id);
int PushButtonSetVisible(int bt,int flag);

int FontAdd(char *foldername);
int FontAdd(char *font,char *style,int points,int color);
//  Arial
//  Courier
//  Georgia
//  Helvetica
//  Times
//  Trebuchet
//  Verdana

int TextAdd(int x,int y,char *text,int font);
int TextSetText(int tx,char *text);
int TextGetText(int tx,char *text);
int TextSetxy(int tx,int x,int y);

int TextSetSize(int tx,int width,int height);		// 04/26/11

int TextGetx(int tx);
int TextGety(int tx);
int TextSetVisible(int tx,int flag);
int TextSetColor(int tx,int color);

int FileOpenAsset(char *filename);
int FileOpen(char *filename);
int FileCreate(char *filename);
int FileRead(int fh,char *buf,int len);
int FileWrite(int fh,char *buf,int len);
int FileSeek(int fh,int seek);
int FileClose(int fh);
int FileDelete(char *filename);	// 1.4

int SoundAdd(char *filename);
int SoundPlay(int sn);
int SoundLoop(int sn);
int SoundStop(int sn);

int Mp3Add(char *filename);
int Mp3Play(int sn);
int Mp3Loop(int sn);
int Mp3Stop(); // only one that can be playing so sn not needed


void DeckShuffle(int deck[52]);

void Printf(char* lpszFormat, ...);

void StrCopy(char *dest,char *src);
void StrAppend(char *dest,char *src);

void LandscapeMode();
void PortraitMode();

int ViewSetRotate(int vw,int degrees);
int ViewSetSize(int vw,int width,int height);

int ViewSetTouch(int vw,int tc);

int TiltGetx();
int TiltGety();
int TiltGetz();

int ViewSetAlpha(int vw,int alpha);

int EditAdd(int x,int y,int width);
int EditSetLabel(int ed,char *text);
int EditSetText(int ed,char *text);
int EditGetText(int ed,char *text);
int EditSetVisible(int ed,int flag);
int EditSetOnDone(int (*callback)(void));
int EditSetKeyboard(int ed,int flag);
int EditSetFocus(int ed,int flag);

int NoteAdd(int x,int y,int width,int height);
int NoteSetText(int ed,char *text);
int NoteGetText(int ed,char *text);
int NoteSetVisible(int ed,int flag);
int NoteSetOnDone(int (*callback)(void));
int NoteSetEditable(int ed,int flag);

int DrawAdd(int x,int y,int width,int height);
int DrawSetVisible(int dr, int flag);
int DrawSetxy(int dr, int x,int y);

int DrawClear(int dr); // handle to drawing surface from DrawAdd
int DrawSetPenWidth(int dr,int width);
int DrawSetColor(int dr,int color);
int DrawSetFillColor(int dr,int color);
int DrawMoveTo(int dr,int x,int y);
int DrawLineTo(int dr,int x,int y);
int DrawCurveTo(int dr,int x,int y);
int DrawFill(int dr); // (uses draw color) from pt inside?
int DrawSquare(int dr,int x,int y,int width,int height); // or Rectangle
int DrawSquareFill(int dr,int x,int y,int width,int height); // or Rectangle
int DrawCircle(int dr,int x,int y,int width,int height); // or Ellipse
int DrawCircleFill(int dr,int x,int y,int width,int height); // or Ellipse
int DrawLine(int dr,int x1,int y1,int x2,int y2);
int DrawArc(int dr,int x,int y,int radius,int begin,int end);
int DrawPoly(int dr,int *points);
int DrawPolyFill(int dr,int *points);

int BitmapAdd(int x,int y,int width,int height);
int BitmapSetVisible(int bi,int flag);
unsigned char *BitmapGetBits(int bi);
int BitmapUpdate(int bi); // notify sys that bits have changed
void BitmapSetPixel(int bi,int x,int y,int r,int g,int b,int a);
void BitmapSetPixel(int bi,int x,int y,int color); // color=0xBBGGRRAA premultiplied bgr with alpha (iphone native)
int BitmapSetxy(int bi,int x,int y);
int BitmapSetImage(int bi,int im);

int LcdStayOn(int flag);

int NetSend(char *url,int (*callback)(int event,char *response,int len)); // event: 0=failed, 1=success

int TimerAdd(int (*callback)(int),int id);
int TimerDelete(int li);
unsigned int TimerGetMsExpired();
unsigned int TimerGetMs();

//----------------------------
int DirBegin(char *value,char *ext);
int DirNext(char *value, int len);
int DirEnd();

int AutoRotateInit(int allow,int (*callback)(int)); // allow 0=none,1=portrait, 2=landscape, 3=both - call this last in AppMain so all images and views avail
int ButtonSetxy(int bt,int x,int y);
int PushButtonSetxy(int bt,int x,int y);

void Vibrate();

int LocationGet(float &lat, float &lng);
void LocationMonitorLocation(int flag);
void LocationMonitorHeading(int flag);
float LocationDistanceFrom(float lat, float lng);
float LocationDistanceBetween(float lat1, float lng1,float lat2, float lng2);
float LocationGetAltitude();
float LocationGetHorizontalAccuracy();	
float LocationGetVerticalAccuracy();	
float LocationGetCourse();	
float LocationGetSpeed();	
float LocationGetHeading();


int AdBannerInit(int location);	// 0=top, 1=bottom
int AdBannerSetLocation(int location); // 0=top, 1=bottom
int AdBannerSetVisible(int flag);

int DeviceGetBatteryLevel();
int DeviceGetBatteryState();
int DeviceGetModel(char *value, int len);
int DeviceGetName(char *value, int len);
int DeviceGetSystemName(char *value, int len);
int DeviceGetSystemVersion(char *value, int len);
int DeviceGetUDID(char *value, int len);
void DeviceSetBatteryMonitoring(int flag);
int DeviceGetMultitaskingSupported();
int DeviceGetLocaleID(char *value, int len);
int DeviceGetUIType();

int BrowserLaunch(char *url);

int ImageSetImage(int im,char *filename); // reuse an image deleting old one

//------------------
int SQLiteOpen(char *filename);
int SQLiteClose();
int SQLiteExec(char *query);
int SQLiteSetOnColumn(int (*callback)(char *value,char *name));
int SQLiteSetOnRow(int (*callback)(char *value));
const char *SQLiteGetLastError();
//------------------
// Container support
int ContainerAdd(int cn,int x,int y);
int ContainerSetxy(int cn,int x,int y);
int ContainerSetx(int cn,int x);
int ContainerSety(int cn,int y);
int ContainerGetx(int cn);
int ContainerGety(int cn);
int ContainerSetVisible(int cn,int flag);

int ContainerOrderFront(int pcn,int cn);
int ContainerOrderBack(int pcn,int cn);	// ret 0=not found, 1=found and moved

int ViewAdd(int cn,int im,int x,int y);
int ViewAdd(int cn,char *filename,int x,int y);
int ViewAdd(int cn,char *filename,int x,int y,int (*callback)(int id,int event,int x,int y),int id);

int ViewAdd(int cn,int im,int x,int y,int (*callback)(int id,int event,int x,int y),int id);
int ViewAdd(int im,int x,int y,int (*callback)(int id,int event,int x,int y),int id);

int TouchAdd(int cn,int x,int y,int width,int height,int (*callback)(int id,int event,int x,int y),int id); // event: 1=down, 2=move, 3=up
int TextAdd(int cn, int x,int y,char *text,int font);
int EditAdd(int cn,int x,int y,int width);
int NoteAdd(int cn,int x,int y,int width,int height);
int ButtonAdd(int cn,char *filename,int x,int y,int (*callback)(int id),int id);
int PushButtonAdd(int cn,char *filename,int x,int y,int (*callback)(int id),int id);

//------------------
int CameraSave(char *filename, void (*callback)(int type));
int AlbumSave(char *filename, void (*callback)(int type));

//------------------
int GameCenterInit(void(*callback)(int type, int flag, int value, char *desc));
int GameCenterLeaderboardShow();
int GameCenterLeaderboardPostScore(char *board_id, int score);
int GameCenterAchievementsShow();
int GameCenterAchievementsPost(char *achievement_id, float percent);
int GameCenterAchievementsReset();
int GameCenterGetLeaderboardRank(char *board_id);

//------------------
int StoreInit(void (*callback)(int,int,int,char*),char delimiter);
int StorePurchaseProduct(char *product_id);
void StoreRequestProductData(char *product_ids);

//------------------
int TouchSetWidth(int tc,int width);
int TouchSetHeight(int tc,int height);

//------------------
int FileLength(int fh);

//------------------
int SuspendInit(void(*callback)());

#define printf Printf
