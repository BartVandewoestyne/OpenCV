/**
 * Exercise 3-08.
 */

#include <highgui.h>
#include <cv.h>

typedef struct {
    int i;
    CvPoint point;
    CvRect rect;
} my_struct;


void write_my_struct(CvFileStorage* fs, const char* name, my_struct* ms);
void read_my_struct(CvFileStorage* fs, CvFileNode* ms_node, my_struct* ms);
void print_my_struct(my_struct *ms);


int main( int argc, char* argv[] ) {

    my_struct ms;
    ms.i = 123;
    ms.point = cvPoint(4,5);
    ms.rect = cvRect(6, 7, 8, 9);

    CvFileStorage* fs_write = cvOpenFileStorage( "my_struct1.xml", NULL, CV_STORAGE_WRITE );
    write_my_struct( fs_write, "Hello my_struct!", &ms);
    cvReleaseFileStorage( &fs_write );

    my_struct ms_read;
    CvFileStorage *fs_read = cvOpenFileStorage ("my_struct2.xml", NULL, CV_STORAGE_READ);
    read_my_struct(fs_read, NULL, &ms_read);
    cvReleaseFileStorage(&fs_read);

    print_my_struct( &ms_read );

    return 0;

}


void write_my_struct( CvFileStorage* fs, const char* name, my_struct* ms) {

    cvWriteComment (fs, name, 0);

    cvWriteInt(fs, "integer", ms->i);
    
    cvStartWriteStruct(fs, "point", CV_NODE_SEQ);
    cvWriteInt(fs, 0, ms->point.x);
    cvWriteInt(fs, 0, ms->point.y);
    cvEndWriteStruct(fs);

    cvStartWriteStruct(fs, "rectangle", CV_NODE_SEQ);
    cvWriteInt(fs, 0, ms->rect.x);
    cvWriteInt(fs, 0, ms->rect.y);
    cvWriteInt(fs, 0, ms->rect.width);
    cvWriteInt(fs, 0, ms->rect.height);
    cvEndWriteStruct(fs);

}


void read_my_struct( CvFileStorage* fs, CvFileNode* ms_node, my_struct* ms) {

    ms->i = cvReadIntByName(
      fs,
      NULL,       // search a top-level node
      "integer",  // node name
      456         // default value
    );

    CvSeq *s;

    s = cvGetFileNodeByName(fs, 0, "point")->data.seq;
    ms->point.x = cvReadInt( (CvFileNode *)cvGetSeqElem(s, 0) );
    ms->point.y = cvReadInt( (CvFileNode *)cvGetSeqElem(s, 1) );
    
    s = cvGetFileNodeByName(fs, 0, "rectangle")->data.seq;
    ms->rect.x = cvReadInt( (CvFileNode *)cvGetSeqElem(s, 0) );
    ms->rect.y = cvReadInt( (CvFileNode *)cvGetSeqElem(s, 1) );
    ms->rect.width = cvReadInt( (CvFileNode *)cvGetSeqElem(s, 2) );
    ms->rect.height = cvReadInt( (CvFileNode *)cvGetSeqElem(s, 3) );

}

void print_my_struct(my_struct *ms)
{
    printf("my_struct:\n"
           "  integer: %d\tpoint: (%d, %d)\trectangle: (%d, %d, %d, %d)\n",
           ms->i,
           ms->point.x, ms->point.y,
           ms->rect.x, ms->rect.y, ms->rect.width, ms->rect.height);
}
