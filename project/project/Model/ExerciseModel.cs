using SQLite;
using SQLiteNetExtensions.Attributes;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;

namespace project.Model
{
    [Table("NewTable1")]
    public class ExerciseModel
    {
        [PrimaryKey, AutoIncrement]
        public int Id { get; set; }
        public string Name { get; set; }
        [TextBlob("DataBlobbed")]
        public List<LogModel> Data { get; set; }
        public string DataBlobbed { get; set; }
    }
}
