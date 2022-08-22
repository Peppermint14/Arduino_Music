import zipfile
import csv
import xml.etree.ElementTree as ET
from pathlib import Path

def createHeaderFile(name, notes, durations, dots, tempo):
    header = open(name+".hpp", "w")
    header.write(
        "#ifndef " + (name+"_HPP").capitalize()+"\n"+
        "#define " + (name+"_HPP").capitalize()+"\n"+
        "\n" + "float tempo = " + str(tempo) + ";\n\n" +

        "int notes[] = {" + ', '.join(map(str,notes)) +
        
        "};\n"+
        "int len_notes = " + str(len(notes)) + "\n"
        "\n" +
        "int duration[] = {" +  ', '.join(map(str,durations)) +
        
        "};\n"+
        "int len_duration = " + str(len(durations)) + "\n"
        "\n" +
        "int dots[] = {" + ', '.join(map(str,dots)) +
        
        "};\n"+
        "int len_dots = " + str(len(dots)) + "\n"
        
        "\n#endif //" + (name+"_HPP").capitalize()+"\n"
        
    )

def parseMuse(museFile_path):
    tree = ET.fromstring(museFile_path)
    root = tree.getroot()

    filename = Path(museFile_path).resolve()
    textpath = Path(str(filename) + ".txt")
    print("----")
    print(filename)
    print(type(filename))
    print(str(Path.cwd()))
    print(str(textpath))
    print("----")

    file1 = open(textpath, "w") 

    tempo = root.findtext(".//Tempo/tempo")
    file1.write("tempo: " + tempo + "\n")
    file1.write("Measure, pitch, tpc, dots, duration\n")
    
    hand = "handswitch"


    for measure in root.findall('.//Measure'):
        for chords in measure.findall(".//durationType/.."):

            duration = chords.find('durationType').text
            pitch = chords.find(".//pitch")
            tpc = chords.find(".//tpc")            
            dots = chords.find(".//dots")
            # if()
            file1.write(
                        str(measure.get("number")) + ", " +
                        str("-1" if pitch is None else pitch.text) + ", " +
                        str("-1" if tpc is None else  tpc.text) + ", " + 
                        str("0" if dots is None else  dots.text) + ", " + str(notelength_str_to_int(duration)) + "\n"
                        # + str(chords.find('.//pitch').text) + "\n"
                        )

            # file1.write(chords.attrib)
        # duration = item.find('.//durationType/').text
        # midinote = 0
        # pitch = 0
        # tpc = 0
        # note = item.find('.//Note')
        # if(note):

        #     pitch = note.find('pitch').text
        #     tpc = note.find('tpc').text

        # if(item.get('number') == '1'):
        #     print(hand)
        #     print(item.tag, item.attrib, duration)
        #     print(pitch, tpc)
    file1.close()


def notelength_str_to_int(string):
    switcher={
        "measure": 1,
        "whole": 1,
        "half": 2,
        "quarter": 4,
        "eighth": 8,
        "16th": 16,
    }
    return switcher.get(string, "invalid arg: " + str(string))


def main(filepath="playing-music/musesheets/Alle_Meine_Entchen_nr.mscx"):
    # load rss from web to update existing xml file
    # ()
    newpath = Path(filepath)
    print("----")
    print(filepath)
    print(type(filepath))
    print("----")
    print(newpath)
    print(type(newpath))
    print("----")
    tempo = 0
    durations = [0, 2, 5]
    notes = []
    dots = []
  
    # # parse xml file
    newsitems = parseMuse(filepath)
    createHeaderFile("testing_convertor", notes, durations, dots, tempo)

    # with zipfile.ZipFile('Bohemian_Rhapsody_for_Piano.mscz') as file:
    #     print(file.getinfo(file.namelist()[-1]))
    # store news items in a csv file
    # savetoCSV(newsitems, 'topnews.csv')
      
      
if __name__ == "__main__":
    import argparse
    # parser = argparse.ArgumentParser(description='Converting musescore file')
    # parser.add_argument('musescore_path', metavar='File', type=Path, nargs='?')
    # parser.add_argument('-t', '--filetype', choices=['R', 'Z'], default='R', help='Specifies the type of musescore file. MSCZ/compressed -> Z, MSCX/Raw -> R')
    # args = parser.parse_args()
    # print(Path(args.musescore_path).absolute())
    main()


