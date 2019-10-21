//
//  Article.swift
//  ozhadaie2019
//
//  Created by Oleksii ZHADAIEV on 10/11/19.
//
//

import Foundation
import CoreData


//extension Article {
//
//    @nonobjc public class func fetchRequest() -> NSFetchRequest<Article> {
//        return NSFetchRequest<Article>(entityName: "Article")
//    }
//
//    @NSManaged public var content: String?
//    @NSManaged public var creationData: NSDate?
//    @NSManaged public var image: NSData?
//    @NSManaged public var language: String?
//    @NSManaged public var modificationData: NSDate?
//    @NSManaged public var title: String?
//
//    override public var description: String {
//        return "Description"
//    }
//
//}

public class Article: NSManagedObject {
    
    @nonobjc public class func fetchRequest() -> NSFetchRequest<Article> {
        return NSFetchRequest<Article>(entityName: "Article")
    }
    
    @NSManaged public var title: String?
    @NSManaged public var content: String?
    @NSManaged public var language: String?
    @NSManaged public var image: NSData?
    @NSManaged public var creationDate: NSDate?
    @NSManaged public var modificationDate: NSDate?
    
    override public var description: String {
        return ("Title: \(String(describing: title)),\nlanguage: \(String(describing: language)),\ncontent: \(String(describing: content)),\ncreationDate: \(String(describing: creationDate)),\nmodificationDate: \(String(describing: modificationDate))")
    }
}
